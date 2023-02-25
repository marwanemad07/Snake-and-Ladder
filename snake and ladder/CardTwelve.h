#pragma once
#include"Card.h"
#include "CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"

class CardTwelve :public Card
{
	CardNine* nine;
	CardTen *ten;
	CardEleven *eleven;
public:
	CardTwelve(const CellPosition& pos);
	void  Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	~CardTwelve();
};