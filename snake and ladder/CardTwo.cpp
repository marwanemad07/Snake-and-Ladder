#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) :Card(pos)
{
	SetCardNumber(2);
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder* ladder = pGrid->GetNextLadder(position);
	if (pGrid->GetNextLadder(position) != NULL)
	{

		pGrid->UpdatePlayerCell(pPlayer, ladder->GetEndPosition());
	}
	else
		return;

}
void CardTwo::ReadCardParameters(Grid* pGrid)
{

}
void CardTwo::Save(ofstream& OutFile, Type obj) {
	if (obj == card)
		Card::Save(OutFile, obj);
	OutFile << endl;
}
void CardTwo::Load(ifstream& Infile, Type obj) {
	if (obj == card) {
		Card::Load(Infile, obj);
	}
}
CardTwo::~CardTwo()
{

}