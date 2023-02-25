#pragma once
#include "Card.h"

class CardFive : public Card
{
private:
	CellPosition newPosition;
	Cell* currentCell;
	int justRolledDiceNum;
	int newCell;
public:
	CardFive(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	~CardFive();
};

