#include "sppch.h"
#include "EditorApplication.h"

#include "Editor/EditorLayer.h"

FEditorApplication::FEditorApplication()
{
	GApplication = this;
}

FEditorApplication::~FEditorApplication()
{
}

void FEditorApplication::OnInit()
{
	m_pEditorLayer = new FEditorLayer();
	PushLayer( m_pEditorLayer );
}

void FEditorApplication::OnShutdown()
{
	PopLayer( m_pEditorLayer );
}
