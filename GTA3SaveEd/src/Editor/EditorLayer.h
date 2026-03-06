#pragma once

#include "Core/Layer.h"

#include "GTA/SaveFile.h"

class FEditorLayer : public Layer
{
public:
	FEditorLayer();
	~FEditorLayer();

	virtual void OnUpdate( FTimestep time ) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent( Event& rEvent ) override;
	virtual void OnAttach() override;

private:
	void DrawSelectSavePopup();
	void DrawSimpleVarsEditor();
	void DrawGaragesEditor();
	void DrawPlayerInfoEditor();

private:
	std::filesystem::path m_SaveFileDirectory;
	std::vector<std::filesystem::path> m_FoundSaveFiles;
	std::shared_ptr<FSaveFile> m_SaveFile;

	int64_t m_SelectedSaveFileIndex = -1;
	bool m_ShowSelectSavePopup = false;

};
