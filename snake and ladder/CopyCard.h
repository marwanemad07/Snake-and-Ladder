#pragma once
#include "Action.h"
class CopyCard : public Action
{     
	Cell *copy;
public:
	CopyCard(ApplicationManager *pApp);
	virtual void ReadActionParameters(); 

	virtual void Execute();
	~CopyCard();
};

