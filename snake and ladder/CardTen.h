#pragma once
#include"Card.h"
class CardTen :public Card
{
private:
	static int CardPrice;
	static int Fees;
	static	bool flag;
	static bool buy;
	static Player* owner;

public:
	int getCardprice();
	CardTen(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	Player* getOwner();
	void setOwner(Player*);
	void deleteOwner();
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	virtual ~CardTen();
};