#include "Ladder.h"
#include "Card.h"
#include "Snake.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{

	///TODO: Do the needed validation
	if(endCellPos.IsValidCell())
		this->endCellPos = endCellPos; // it was written in the first line
	ladderCounter++;
	// it should include an else statmenet //Emad

}
int Ladder::GetLadderCounter() {
	return ladderCounter;
}
int Ladder::ladderCounter = 0;

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	int x, y;

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continute...");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//		
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());

	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}



bool Ladder::IsOverLapping(GameObject* newObj) const
{
	Ladder* passedLadder = dynamic_cast<Ladder*>(newObj);
	// i think i can write a condition to handle the two cases.
	if (passedLadder != NULL )
	{
		int	PL_startCell = passedLadder->GetPosition().GetCellNum();
		int PL_endCell = passedLadder->GetEndPosition().GetCellNum();
		int CL_currCell = this->GetPosition().GetCellNum();
		int CL_currCellTemp = CL_currCell;
		int CL_endCell = this->GetEndPosition().GetCellNum();
		while (CL_currCellTemp <= CL_endCell)
		{
			if (CL_currCellTemp == PL_startCell)
				return true;
			CL_currCellTemp += 11;
			
		}
		while (PL_startCell <= PL_endCell)
		{
			if (PL_startCell == CL_currCell)
				return true;
			PL_startCell += 11;
		}
	}

	return false;
}

//bool Ladder::IsStartLadder(GameObject* newObj) const
//{
//
//}
void Ladder::Save(ofstream& OutFile, Type obj) {
	if (obj == ladder)
		OutFile << GetPosition().GetCellNum() << " " << GetEndPosition().GetCellNum() << endl;

}
void Ladder::SetEndPosition(CellPosition pos) {
	if (pos.IsValidCell()) {
		endCellPos = pos;
	}
}
void Ladder::Load(ifstream& Infile, Type obj) {
	int startpos, endpos;

	if (obj == ladder) {
		Infile >> startpos >> endpos;
		setPosition(position.GetCellPositionFromNum(startpos));
		SetEndPosition(position.GetCellPositionFromNum(endpos));

	}
}
bool Ladder::IntersectWithSnake(GameObject* newObj) const
{
	Ladder* ladder = dynamic_cast<Ladder*>(newObj);
	if (ladder == NULL)
	{
		Snake* snake = dynamic_cast<Snake*>(newObj);
		int ladderEndCell = this->GetEndPosition().GetCellNum();
		int SnakeStartCell = snake->GetPosition().GetCellNum();
		int ladderStartCell = this->GetPosition().GetCellNum();
		int SnakeEndCell = snake->GetEndPosition().GetCellNum();
		if (ladderEndCell == SnakeStartCell)
			return true;
		if (ladderStartCell == SnakeStartCell)
			return true;
		if (ladderStartCell == SnakeEndCell)
			return true;
	}
	return false;
}

bool Ladder::IntersectWithLadder(GameObject* newObj) const
{
	return false;
}

Ladder::~Ladder()
{
	ladderCounter--;
}