#pragma once

#include "Application.h"

class FEditorLayer;

class FEditorApplication : public FApplication
{
public:
	FEditorApplication();
	virtual ~FEditorApplication();

protected:
	virtual void OnInit() override;
	virtual void OnShutdown() override;

private:
	FEditorLayer* m_pEditorLayer = nullptr;
};
