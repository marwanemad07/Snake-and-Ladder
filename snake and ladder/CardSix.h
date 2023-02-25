#pragma once
#include"Card.h"

class CardSix :public Card
{
private:
	CellPosition CelltoMove;
	static int toCellnumber;
	static bool flag;
public:
	CardSix(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	~CardSix();
};

