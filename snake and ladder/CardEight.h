#pragma once
#include"Card.h"

class CardEight : public Card
{
private:
	double  Price;
	static bool flag;
	int counter;
public:
	int getCardprice();
	CardEight(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	virtual ~CardEight();
};
