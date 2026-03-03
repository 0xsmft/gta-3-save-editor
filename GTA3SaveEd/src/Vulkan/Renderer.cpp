/********************************************************************************************
*                                                                                           *
*                                                                                           *
*                                                                                           *
* MIT License                                                                               *
*                                                                                           *
* Copyright (c) 2020 - 2026 BEAST                                                           *
*                                                                                           *
* Permission is hereby granted, free of charge, to any person obtaining a copy              *
* of this software and associated documentation files (the "Software"), to deal             *
* in the Software without restriction, including without limitation the rights              *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                 *
* copies of the Software, and to permit persons to whom the Software is                     *
* furnished to do so, subject to the following conditions:                                  *
*                                                                                           *
* The above copyright notice and this permission notice shall be included in all            *
* copies or substantial portions of the Software.                                           *
*                                                                                           *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                  *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE               *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                    *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,             *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE             *
* SOFTWARE.                                                                                 *
*********************************************************************************************
*/

#include "sppch.h"
#include "Renderer.h"

#include "VulkanDebug.h"

namespace Saturn {

	//////////////////////////////////////////////////////////////////////////

	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Init()
	{
		// Create Sync objects.
		VkSemaphoreCreateInfo SemaphoreCreateInfo = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
		VkFenceCreateInfo     FenceCreateInfo = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
		FenceCreateInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

		m_FlightFences.resize( MAX_FRAMES_IN_FLIGHT );

		for( int i = 0; i < MAX_FRAMES_IN_FLIGHT; i++ )
		{
			VK_CHECK( vkCreateFence( VulkanContext::Get().GetDevice(), &FenceCreateInfo, nullptr, &m_FlightFences[ i ] ) );
		}

		VK_CHECK( vkCreateSemaphore( VulkanContext::Get().GetDevice(), &SemaphoreCreateInfo, nullptr, &m_AcquireSemaphore ) );
		VK_CHECK( vkCreateSemaphore( VulkanContext::Get().GetDevice(), &SemaphoreCreateInfo, nullptr, &m_SubmitSemaphore ) );

		SetDebugUtilsObjectName( "Acquire Semaphore", ( uint64_t ) m_AcquireSemaphore, VK_OBJECT_TYPE_SEMAPHORE );
		SetDebugUtilsObjectName( "Submit Semaphore", ( uint64_t ) m_SubmitSemaphore, VK_OBJECT_TYPE_SEMAPHORE );
	}

	void Renderer::Terminate()
	{
		// Terminate Semaphores.
		if( m_AcquireSemaphore )
			vkDestroySemaphore( VulkanContext::Get().GetDevice(), m_AcquireSemaphore, nullptr );

		if( m_SubmitSemaphore )
			vkDestroySemaphore( VulkanContext::Get().GetDevice(), m_SubmitSemaphore, nullptr );

		m_AcquireSemaphore = nullptr;
		m_SubmitSemaphore = nullptr;

		if( m_FlightFences.size() )
		{
			for( int i = 0; i < m_FlightFences.size(); i++ )
			{
				vkDestroyFence( VulkanContext::Get().GetDevice(), m_FlightFences[ i ], nullptr );
			}
		}

		for( auto& rFunc : m_TerminateResourceFuncs )
			rFunc();
	}

	void Renderer::BeginRenderPass( VkCommandBuffer CommandBuffer, Pass& rPass )
	{
	}

	void Renderer::EndRenderPass( VkCommandBuffer CommandBuffer )
	{
		vkCmdEndRenderPass( CommandBuffer );
	}

	VkCommandBuffer Renderer::AllocateCommandBuffer( VkCommandPool CommandPool )
	{
		VkCommandBufferAllocateInfo AllocateInfo = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
		AllocateInfo.commandPool = VulkanContext::Get().GetCommandPool();
		AllocateInfo.commandBufferCount = 1;
		AllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;

		VkCommandBuffer CommandBuffer;
		VK_CHECK( vkAllocateCommandBuffers( VulkanContext::Get().GetDevice(), &AllocateInfo, &CommandBuffer ) );

		VkCommandBufferBeginInfo CommandPoolBeginInfo = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
		CommandPoolBeginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

		VK_CHECK( vkBeginCommandBuffer( CommandBuffer, &CommandPoolBeginInfo ) );

		return CommandBuffer;
	}

	VkCommandBuffer Renderer::AllocateCommandBuffer( VkCommandBufferLevel CmdLevel )
	{
		VkCommandBufferAllocateInfo AllocateInfo = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
		AllocateInfo.commandPool = VulkanContext::Get().GetCommandPool();
		AllocateInfo.commandBufferCount = 1;
		AllocateInfo.level = CmdLevel;

		VkCommandBuffer CommandBuffer;
		VK_CHECK( vkAllocateCommandBuffers( VulkanContext::Get().GetDevice(), &AllocateInfo, &CommandBuffer ) );

		return CommandBuffer;
	}

	void Renderer::BeginFrame()
	{
		VkDevice LogicalDevice = VulkanContext::Get().GetDevice();

		m_CommandBuffer = AllocateCommandBuffer( VulkanContext::Get().GetCommandPool() );

		// Wait for last frame.
		VK_CHECK( vkWaitForFences( LogicalDevice, 1, &m_FlightFences[ m_FrameCount ], VK_TRUE, UINT32_MAX ) );

		// Reset current fence.
		VK_CHECK( vkResetFences( LogicalDevice, 1, &m_FlightFences[ m_FrameCount ] ) );

		// Acquire next image.
		uint32_t ImageIndex = UINT32_MAX;
		VulkanContext::Get().GetSwapchain().AcquireNextImage( UINT32_MAX, m_AcquireSemaphore, VK_NULL_HANDLE, &ImageIndex );

		m_ImageIndex = ImageIndex;
	}

	void Renderer::EndFrame()
	{
		VkDevice LogicalDevice = VulkanContext::Get().GetDevice();

		VK_CHECK( vkEndCommandBuffer( m_CommandBuffer ) );

		// Rendering Queue
		VkPipelineStageFlags WaitStage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;

		VkSubmitInfo SubmitInfo = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
		SubmitInfo.commandBufferCount = 1;
		SubmitInfo.pCommandBuffers = &m_CommandBuffer;
		SubmitInfo.pWaitDstStageMask = &WaitStage;

		// SIGNAL the SubmitSemaphore
		SubmitInfo.pSignalSemaphores = &m_SubmitSemaphore;
		SubmitInfo.signalSemaphoreCount = 1;

		// WAIT for AcquireSemaphore
		SubmitInfo.pWaitSemaphores = &m_AcquireSemaphore;
		SubmitInfo.waitSemaphoreCount = 1;

		VK_CHECK( vkResetFences( LogicalDevice, 1, &m_FlightFences[ m_FrameCount ] ) );

		// Use current fence to be signaled.
		VK_CHECK( vkQueueSubmit( VulkanContext::Get().GetGraphicsQueue(), 1, &SubmitInfo, m_FlightFences[ m_FrameCount ] ) );

		// Present info.
		VkPresentInfoKHR PresentInfo = { VK_STRUCTURE_TYPE_PRESENT_INFO_KHR };
		PresentInfo.pSwapchains = &VulkanContext::Get().GetSwapchain().GetSwapchain();
		PresentInfo.swapchainCount = 1;
		PresentInfo.pImageIndices = &m_ImageIndex;

		// WAIT for SubmitSemaphore
		PresentInfo.pWaitSemaphores = &m_SubmitSemaphore;
		PresentInfo.waitSemaphoreCount = 1;

		{
			VkResult Result = vkQueuePresentKHR( VulkanContext::Get().GetGraphicsQueue(), &PresentInfo );

			if( Result == VK_ERROR_OUT_OF_DATE_KHR )
			{
				XY_CORE_INFO( "Result was VK_ERROR_OUT_OF_DATE_KHR, Swapchain will be re-created!" );

				VulkanContext::Get().GetSwapchain().Recreate();

				PresentInfo.pSwapchains = &VulkanContext::Get().GetSwapchain().GetSwapchain();

				VK_CHECK( vkQueuePresentKHR( VulkanContext::Get().GetGraphicsQueue(), &PresentInfo ) );
			}
		}

		{
			VK_CHECK( vkQueueWaitIdle( VulkanContext::Get().GetPresentQueue() ) );
		}

		vkFreeCommandBuffers( LogicalDevice, VulkanContext::Get().GetCommandPool(), 1, &m_CommandBuffer );

		m_FrameCount = ( m_FrameCount + 1 ) % MAX_FRAMES_IN_FLIGHT;
	}

	void Renderer::SubmitTerminateResource( std::function<void()>&& rrFunction )
	{
		m_TerminateResourceFuncs.push_back( rrFunction );
	}

}
