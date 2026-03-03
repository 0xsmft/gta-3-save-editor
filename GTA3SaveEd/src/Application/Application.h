#pragma once

#include "Ruby/RubyEvent.h"
#include "ImGui/ImGuiLayer.h"
#include "Core/Timestep.h"

class RubyWindow;

class FApplication : public RubyEventTarget
{
public:
	FApplication();
	virtual ~FApplication();

	void Run();
	void Close();

	std::shared_ptr<RubyWindow> GetWindow() const { return m_Window; }

	void PushLayer( Layer* pLayer );
	void PopLayer( Layer* pLayer );

protected:
	virtual bool OnEvent( Event& rEvent ) override;

	virtual void OnInit() {}
	virtual void OnShutdown() {}

private:
	void BuildRenderCommands(); 
	void InitWindow();
	void OnWindowResize( RubyWindowResizeEvent& rEvent );

private:
	float m_LastFrameTime = 0.0f;
	FTimestep m_Timestep;
	bool m_Running = true;

	std::vector<Layer*> m_Layers;
	std::unique_ptr<ImGuiLayer> m_ImGuiLayer;
	std::shared_ptr<RubyWindow> m_Window = nullptr;
};

extern FApplication* GApplication;
