#pragma once
#include "Action.h"

class PasteCard : public Action
{          
	CellPosition cardPosition;
public:
	PasteCard(ApplicationManager *pApp);
	virtual void ReadActionParameters(); 

	virtual void Execute();
virtual	~PasteCard();
};

