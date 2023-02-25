#pragma once
#include "SaveGrid.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include "Action.h"
#include<fstream>
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
class OpenGrid :public Action
{
private:string filename;
	   ifstream input;
public:
	OpenGrid(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~OpenGrid();
};

