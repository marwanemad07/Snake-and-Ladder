#pragma once
#include "Action.h"
class CutCard : public Action
{
	Cell *Cut;
public:
	CutCard(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	~CutCard();
};


