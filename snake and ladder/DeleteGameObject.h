#pragma once
#include "Action.h"
class DeleteGameObject : public Action
{
	Cell* Delete;
	CellPosition deletePosition;
public:
	DeleteGameObject(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteGameObject();
};

