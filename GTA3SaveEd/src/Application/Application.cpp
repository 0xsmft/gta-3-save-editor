#include "sppch.h"
#include "Application.h"

#include "Vulkan/Renderer.h"

#include "Ruby/RubyWindow.h"

FApplication* GApplication = nullptr;

using namespace Saturn;

FApplication::FApplication()
{
	if( GApplication )
		__debugbreak();

	GApplication = this;

	InitWindow();

	VulkanContext::Get().Init();

	m_ImGuiLayer = std::make_unique<ImGuiLayer>();

	PushLayer( m_ImGuiLayer.get() );
}

void FApplication::BuildRenderCommands()
{
	for( auto& rLayer : m_Layers )
	{
		rLayer->OnUpdate( m_Timestep );
	}

	m_ImGuiLayer->Begin();

	for( auto& rLayer : m_Layers )
	{
		rLayer->OnImGuiRender();
	}

	m_ImGuiLayer->End( Renderer::Get().ActiveCommandBuffer() );
}

void FApplication::InitWindow()
{
	RubyWindowSpecification windowSpec{ .Name = L"Saturn", .Width = 1280u, .Height = 720u, .GraphicsAPI = RubyGraphicsAPI::Vulkan, .Style = RubyStyle::Default, .ShowNow = true };

	m_Window = std::make_shared<RubyWindow>( windowSpec );
	m_Window->SetEventTarget( this );
}

void FApplication::OnWindowResize( RubyWindowResizeEvent& rEvent )
{
	const int width = rEvent.GetWidth(), height = rEvent.GetHeight();

	if( width == 0 && height == 0 )
		return;

	VulkanContext::Get().ResizeEvent();
}

FApplication::~FApplication()
{
	GApplication = nullptr;
}

void FApplication::Run()
{
	OnInit();

	while( m_Running )
	{
		RubyLibrary::PollEvents();

		if( !m_Window->Minimized() )
		{
			Renderer::Get().BeginFrame();
			{
				BuildRenderCommands();
			}
			Renderer::Get().EndFrame();
		}
		else
			std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );

		const float time = ( float ) m_Window->GetTime();
		const float frametime = time - m_LastFrameTime;

		m_Timestep = std::min<float>( frametime, 0.0333f );

		m_LastFrameTime = time;
	}

	OnShutdown();
}

void FApplication::Close()
{
	m_Running = false;
}

void FApplication::PushLayer( Layer* pLayer )
{
	m_Layers.push_back( pLayer );
	pLayer->OnAttach();
}

void FApplication::PopLayer( Layer* pLayer )
{
	// Find the layer in the layer stack.
	const auto itr = std::find( m_Layers.begin(), m_Layers.end(), pLayer );
	if( itr != m_Layers.end() )
	{
		m_Layers.erase( itr );
		pLayer->OnDetach();
	}
}

bool FApplication::OnEvent( Event& rEvent )
{
	switch( rEvent.Type )
	{
		case EventType::Resize:
		{
			OnWindowResize( ( RubyWindowResizeEvent& ) rEvent );
		} break;

		case EventType::Close:
		{
			Close();
		} break;

		default: break;
	}

	return true;
}
