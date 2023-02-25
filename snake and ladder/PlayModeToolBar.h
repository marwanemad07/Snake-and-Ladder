#pragma once
#include "Action.h"

class PlayModeToolBar : public Action
{
public:
	PlayModeToolBar(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PlayModeToolBar();
};

