#pragma once
#include "Action.h"
#include<fstream>
class SaveGrid : public Action
{
private:string filename;
	   ofstream output;
public:
	SaveGrid(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveGrid();
};

