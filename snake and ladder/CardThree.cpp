#include "CardThree.h"
#include<fstream>

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(3);
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
	
	
	Output* pOut = pGrid->GetOutput();
	int x, y;
	pOut->PrintMessage("You got an extra dice roll, Click to continue...");
	pGrid->GetInput()->GetPointClicked(x, y);


}
void CardThree::ReadCardParameters(Grid* pGrid)
{

}
void CardThree::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << endl;
	}
}
void CardThree::Load(ifstream& Infile, Type obj) {
	if (obj == card) {

		Card::Load(Infile, obj);
	}
}
CardThree :: ~CardThree()
{

}

