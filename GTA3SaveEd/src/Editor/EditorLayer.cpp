#include "sppch.h"
#include "EditorLayer.h"

#include <imgui.h>
#include <imgui_internal.h>

FEditorLayer::FEditorLayer()
{
}

FEditorLayer::~FEditorLayer()
{
}

void FEditorLayer::OnUpdate( FTimestep time )
{
}

void FEditorLayer::OnImGuiRender()
{
	ImGui::DockSpaceOverViewport( ImGui::GetWindowViewport() );

	ImGui::Begin( "Hello World" );

	ImGui::End();
}

void FEditorLayer::OnEvent( Event& rEvent )
{

}
