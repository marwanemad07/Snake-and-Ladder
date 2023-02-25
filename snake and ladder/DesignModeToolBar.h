#pragma once
#include "Action.h"
class DesignModeToolBar : public Action
{
public:
	DesignModeToolBar(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DesignModeToolBar();
};

