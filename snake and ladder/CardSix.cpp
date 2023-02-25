#include "CardSix.h"
#include<fstream>


CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	SetCardNumber(6);
}
int CardSix::toCellnumber = 0;
bool CardSix::flag = false;
void CardSix::ReadCardParameters(Grid* pGrid) {

	if (flag)
		return;
	pGrid->GetOutput()->PrintMessage("Please enter cellNumber : ");

	toCellnumber = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	while (toCellnumber < 1 && toCellnumber > 99)
	{
		pGrid->GetOutput()->PrintMessage("Invalid card Price. Enter Valid number: ");
		toCellnumber = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	}
	flag = true;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, CelltoMove.GetCellPositionFromNum(toCellnumber));
}
void CardSix::Save(ofstream& OutFile, Type obj) {
	if (obj == card)
	{
		Card::Save(OutFile, obj);
		OutFile << toCellnumber << " " << flag << endl;
	}
}
void CardSix::Load(ifstream& Infile, Type obj) {
	if (obj == card) {

		Card::Load(Infile, obj);
		Infile >> toCellnumber >> flag;
	}
}
CardSix::~CardSix()
{
}

