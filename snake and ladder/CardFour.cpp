#include "CardFour.h"
#include<fstream>

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(4);
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetCardFour(true);
	Output* pOut = pGrid->GetOutput();
	int x, y;
	pOut->PrintMessage("You are prevented from dice roll next turn, Click to continue...");
	pGrid->GetInput()->GetPointClicked(x, y);
}
void CardFour::ReadCardParameters(Grid* pGrid)
{

}
void CardFour::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << endl;
	}
}
void CardFour::Load(ifstream& Infile, Type obj) {
	if (obj == card) {

		Card::Load(Infile, obj);
	}
}
CardFour::~CardFour()
{

}