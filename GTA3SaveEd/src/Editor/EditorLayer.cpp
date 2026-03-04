#include "sppch.h"
#include "EditorLayer.h"

#include "Application/Application.h"

#include "ImGui/ImGuiAuxiliary.h"

#include <imgui.h>
#include <imgui_internal.h>

#if defined(XY_PLATFORM_WINDOWS)
#include <shlobj.h>
#endif

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

	if( ImGui::BeginMainMenuBar() )
	{
		ImGui::EndMainMenuBar();
	}

	if( m_SaveFile == nullptr ) 
		DrawSelectSavePopup();
	else
	{
		DrawSimpleVarsEditor();
		DrawGaragesEditor();
	}
}

void FEditorLayer::OnEvent( Event& rEvent )
{

}

void FEditorLayer::OnAttach()
{
#if defined(XY_PLATFORM_WINDOWS)
	LPWSTR path = nullptr;
	::SHGetKnownFolderPath( FOLDERID_Documents, 0, nullptr, &path );

	m_SaveFileDirectory = path;
	m_SaveFileDirectory /= "GTA3 User Files";
#endif

	for( const auto& rEntry : std::filesystem::directory_iterator( m_SaveFileDirectory ) )
	{
		auto& rPath = rEntry.path();
		if( rPath.extension() != ".b" )
			continue;

		m_FoundSaveFiles.push_back( rPath );
	}
}

void FEditorLayer::DrawSelectSavePopup()
{
	ImGui::OpenPopup( "Please select a save file##selsavf" );

	if( ImGui::BeginPopupModal( "Please select a save file##selsavf", nullptr, ImGuiWindowFlags_NoSavedSettings ) )
	{
		ImGui::Text( "Please select a save file from the list below." );

		if( ImGui::BeginListBox( "##saves", ImVec2( -FLT_MIN, 0.0f ) ) )
		{
			size_t index = 0llu;
			for( const auto& rPath : m_FoundSaveFiles )
			{
				const std::string& rName = rPath.stem().string();
				bool selected = ( index == m_SelectedSaveFileIndex );

				if( ImGui::Selectable( rName.c_str(), selected ) ) 
				{
					m_SelectedSaveFileIndex = index;
				}

				++index;
			}

			ImGui::EndListBox();
		}

		ImGui::Separator();

		ImGui::BeginHorizontal( "##optionshz" );

		Auxiliary::DisabledFlag disabledIf( m_SelectedSaveFileIndex == -1 );

		if( ImGui::Button( "Done" ) )
		{
			m_SaveFile = std::make_shared<FSaveFile>();
			m_SaveFile->Read( m_FoundSaveFiles[ m_SelectedSaveFileIndex ] );

			m_ShowSelectSavePopup = false;
			ImGui::CloseCurrentPopup();
		}

		disabledIf.Pop();

		if( ImGui::Button( "Quit" ) )
		{
			GApplication->Close();
		}

		ImGui::EndHorizontal();

		ImGui::EndPopup();
	}
}

void FEditorLayer::DrawSimpleVarsEditor()
{
	if( ImGui::Begin( "Basic Information" ) )
	{
		auto& rSimpleData = m_SaveFile->GetSimpleData();

		{
			Auxiliary::ScopedDisabledFlag disabledIf( true );

			ImGui::InputText( "Save Name", (char*) rSimpleData.SaveName, 24 );

			ImGui::Separator();
			ImGui::Text( "Date of save file: %i/%i/%i %i:%i", 
				rSimpleData.Day,
				rSimpleData.Month,
				rSimpleData.Year,
				rSimpleData.Hour,
				rSimpleData.Minute );

			ImGui::Separator();
			switch( rSimpleData.Island )
			{
				case CurrentIsland::Portland:
				{
					ImGui::Text( "Current island: Portland" );
				} break;

				case CurrentIsland::Staunton:
				{
					ImGui::Text( "Current island: Staunton Island" );
				} break;

				case CurrentIsland::Shoreside:
				{
					ImGui::Text( "Current island: Shoreside Vale" );
				} break;

				case CurrentIsland::Unknown:
				default:
					break;
			}

			ImGui::Separator();
			ImGui::Text( "Time in game: %i:%i",
				rSimpleData.GameHour,
				rSimpleData.GameMinute );
		}
	}

	ImGui::End();
}

void FEditorLayer::DrawGaragesEditor()
{
	if( ImGui::Begin( "Garages" ) )
	{
		auto& rGarages = m_SaveFile->GetSaveFileStructure().Garages;

		size_t index = 0llu;
		for( auto& rStoredCar : rGarages.StoredCars )
		{
			if( !rStoredCar.ModelID )
				continue;

			ImGui::PushID( index );

			const auto name = VehicleModelIDToString( rStoredCar.ModelID );
			ImGui::Text( "Name: %s", name.data() );
			ImGui::Text( "Model ID: %i", rStoredCar.ModelID );
			ImGui::Text( "Position: X:%.2f Y:%.2f Z:%.2f", rStoredCar.Position.X, rStoredCar.Position.Y, rStoredCar.Position.Z );
			ImGui::Text( "Rotation: X:%.2f Y:%.2f Z:%.2f", rStoredCar.Rotation.X, rStoredCar.Rotation.Y, rStoredCar.Rotation.Z );

			const auto primaryColorID = VehicleColorIDToString( rStoredCar.PrimaryColorID );
			const auto secondaryColorID = VehicleColorIDToString( rStoredCar.SecondaryColorID );
			ImGui::Text( "Primary Color: %s", primaryColorID.data() );
			ImGui::Text( "Secondary Color: %s", secondaryColorID.data() );

			bool bulletImm = rStoredCar.IsVehicleImmunityFlagSet( VEH_IMM_BULLET );
			bool fireImm = rStoredCar.IsVehicleImmunityFlagSet( VEH_IMM_FIRE );
			bool explosionImm = rStoredCar.IsVehicleImmunityFlagSet( VEH_IMM_EXPLOSION );
			bool damageImm = rStoredCar.IsVehicleImmunityFlagSet( VEH_IMM_COLLISION );
			bool meleeImm = rStoredCar.IsVehicleImmunityFlagSet( VEH_IMM_MELEE );

			ImGui::BeginHorizontal( "##vechimm" );
			ImGui::Text( "Immunities:" );
			ImGui::Spring();
			
			if( ImGui::Checkbox( "Bullet Proof##bullet", &bulletImm ) ) 
			{
				rStoredCar.SetImmunityFlag( VEH_IMM_BULLET, bulletImm );
			}

			if( ImGui::Checkbox( "Fire Proof##fire", &fireImm ) ) 
			{
				rStoredCar.SetImmunityFlag( VEH_IMM_FIRE, fireImm );
			}

			if( ImGui::Checkbox( "Explosion Proof##explosion", &explosionImm ) ) 
			{
				rStoredCar.SetImmunityFlag( VEH_IMM_EXPLOSION, explosionImm );
			}

			if( ImGui::Checkbox( "Damage Proof##collision", &damageImm ) ) 
			{
				rStoredCar.SetImmunityFlag( VEH_IMM_COLLISION, damageImm );
			}

			if( ImGui::Checkbox( "Melee Proof##melee", &meleeImm ) ) 
			{
				rStoredCar.SetImmunityFlag( VEH_IMM_MELEE, meleeImm );
			}

			ImGui::EndHorizontal();

			ImGui::PopID();

			++index;
		}
	}

	ImGui::End();
}
