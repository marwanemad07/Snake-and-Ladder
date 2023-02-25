#pragma once
#include "Card.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGird, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	~CardSeven();
};

