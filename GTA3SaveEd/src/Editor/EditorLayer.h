#pragma once

#include "Core/Layer.h"

class FEditorLayer : public Layer
{
public:
	FEditorLayer();
	~FEditorLayer();

	virtual void OnUpdate( FTimestep time ) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent( Event& rEvent ) override;

private:

};
