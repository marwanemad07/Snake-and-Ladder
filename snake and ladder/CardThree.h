#pragma once
#include "Card.h"
class CardThree : public Card
{	

public:
	CardThree(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	virtual ~CardThree();
};

