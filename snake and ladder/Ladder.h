#pragma once
#include "GameObject.h"
#include<fstream>

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	static int ladderCounter;

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual bool IsOverLapping(GameObject* newObj) const;
	virtual bool IntersectWithSnake(GameObject* newObj) const;
	virtual bool IntersectWithLadder(GameObject* newObj) const;
	void SetEndPosition(CellPosition);
	virtual void Save(ofstream& OutFile, Type obj);
	virtual void Load(ifstream& Infile, Type obj);
	static int GetLadderCounter();
	virtual ~Ladder(); // Virtual destructor
};

