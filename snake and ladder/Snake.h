#pragma once
#include "GameObject.h"
#include<fstream>
class Snake: public GameObject
{
	CellPosition endCellPos;
	static int SnakeCounter;
public:
	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos);
	virtual void Draw(Output* pOut) const;
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	CellPosition GetEndPosition() const;
	virtual void Save(ofstream& OutFile, Type obj);
	void SetEndPosition(CellPosition);
	virtual void Load(ifstream& Infile, Type obj);
	static int getsnakeCounter();
	virtual bool IsOverLapping(GameObject* newObj) const;
	virtual bool IntersectWithLadder(GameObject* newObj) const;
	virtual bool IntersectWithSnake(GameObject* newObj) const;
	virtual ~Snake();
};


