#pragma once

#include "Core/Layer.h"
#include <vulkan.h>

class ImGuiLayer : public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	void Begin();

	void End( VkCommandBuffer CommandBuffer );

	virtual void OnAttach( void ) override;
	virtual void OnDetach( void ) override;
	virtual void OnImGuiRender( void ) {}

	VkDescriptorPool GetPool() const { return m_DescriptorPool; }
	VkDescriptorSetLayout GetLayout() const { return m_DescriptorLayout; }

private:
	VkDescriptorPool m_DescriptorPool = VK_NULL_HANDLE;
	VkDescriptorSetLayout m_DescriptorLayout = VK_NULL_HANDLE;

	VkCommandBuffer m_CommandBuffer = VK_NULL_HANDLE;
};
