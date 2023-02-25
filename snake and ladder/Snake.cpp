#include "Snake.h"
#include "Ladder.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos):GameObject (startCellPos)
{
	if (position.IsValidCell())
		this->endCellPos = endCellPos;
	// it should include an else statmenet //Emad
	SnakeCounter++;
}
int Snake::getsnakeCounter() {
	return SnakeCounter;
}
int Snake::SnakeCounter = 0;

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(GetPosition(), GetEndPosition());
	
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a snake. Click to continute...");
	pIn->GetPointClicked(x, y);
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

bool Snake::IsOverLapping(GameObject* newObj) const
{
	Snake* passedSnake = dynamic_cast<Snake*>(newObj);
	// i think i can write a condition to handle the two cases.
	if (passedSnake != NULL)
	{
		int	PS_startCell = passedSnake->GetPosition().GetCellNum();
		int PS_endCell = passedSnake->GetEndPosition().GetCellNum();
		int CS_currCell = this->GetPosition().GetCellNum();
		int CS_endCell = this->GetEndPosition().GetCellNum();
		int CS_currCellTemp = CS_currCell;
		while (CS_currCellTemp >= CS_endCell)
		{
			if (CS_currCellTemp == PS_startCell)
				return true;
			CS_currCellTemp -= 11;

		}
		while (PS_startCell >= PS_endCell)
		{
			if (PS_startCell == CS_currCell)
				return true;
			PS_startCell -= 11;
		}
	}

	return false;
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake::IntersectWithLadder(GameObject* newObj) const
{
	Snake* snake = dynamic_cast<Snake*>(newObj);
	if (snake == NULL)
	{
		int SnakeStartCell = this->GetPosition().GetCellNum();
		int SnakeEndCell = this->GetEndPosition().GetCellNum();
		int LadderStartCell = newObj->GetPosition().GetCellNum();
		if (SnakeStartCell == LadderStartCell)
			return true;
		if (SnakeEndCell == LadderStartCell)
			return true;
	}
	return false;
}

bool Snake::IntersectWithSnake(GameObject* newObj) const
{
	return false;
}

void Snake::Save(ofstream& OutFile, Type obj) {
	if (obj == snake)
		OutFile << this->GetPosition().GetCellNum() << " " << this->GetEndPosition().GetCellNum() << endl;
}
void Snake::SetEndPosition(CellPosition pos) {
	if (pos.IsValidCell()) {
		endCellPos = pos;
	}
}

void Snake::Load(ifstream& Infile, Type obj) {
	int startpos, endpos;

	if (obj == snake) {
		Infile >> startpos >> endpos;
		setPosition(position.GetCellPositionFromNum(startpos));
		SetEndPosition(position.GetCellPositionFromNum(endpos));

	}
}

Snake::~Snake()
{
	SnakeCounter--;
}