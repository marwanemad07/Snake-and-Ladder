#pragma once
#include"Action.h"
#include"CardEleven.h"
#include"CardTen.h"
#include"CardNine.h"
class NewGame :public Action
{
	CardNine *nine;
	CardTen* Ten;
	CardEleven* Eleven;

public:
	NewGame(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~NewGame();
};

