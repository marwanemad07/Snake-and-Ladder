#pragma once
#include "Card.h"
#include "Ladder.h"
class CardTwo : public Card
{
public:
	CardTwo(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	virtual ~CardTwo();
};

