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

#pragma once

#include "VulkanContext.h"

namespace Saturn {

	class Renderer : public RefTarget
	{
	public:
		XY_SINGLETON_LAZY( Renderer );

	public:
		Renderer();
		~Renderer();

		// Render pass helpers.
		void BeginRenderPass( VkCommandBuffer CommandBuffer, Pass& rPass );
		void EndRenderPass( VkCommandBuffer CommandBuffer );

		// Allocate command buffer.
		VkCommandBuffer AllocateCommandBuffer( VkCommandPool CommandPool );
		VkCommandBuffer AllocateCommandBuffer( VkCommandBufferLevel CmdLevel );

		//////////////////////////////////////////////////////////////////////////
		// FRAME BEGINGING AND ENDING.
		//////////////////////////////////////////////////////////////////////////
		
		void BeginFrame();
		void EndFrame();
		
		uint32_t GetImageIndex()   const { return m_ImageIndex; }
		uint32_t GetCurrentFrame() const { return m_FrameCount; }

		void SubmitTerminateResource( std::function<void()>&& rrFunction );

	public:
		VkCommandBuffer ActiveCommandBuffer() const { return m_CommandBuffer; };

	private:
		void Init();
		void Terminate();

	private:
		uint32_t m_ImageIndex = 0;
		uint32_t m_ImageCount = 0;
		uint32_t m_FrameCount = 0;

		std::vector<VkFence> m_FlightFences;
		std::vector< std::function<void()> > m_TerminateResourceFuncs;
		
		VkSemaphore m_AcquireSemaphore = nullptr;
		VkSemaphore m_SubmitSemaphore = nullptr;

		VkCommandBuffer m_CommandBuffer = nullptr;

	private:
		friend class VulkanContext;
	};
}
