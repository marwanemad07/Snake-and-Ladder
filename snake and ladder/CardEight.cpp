#include "CardEight.h"
#include <algorithm>
#include <fstream>
CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	SetCardNumber(8);
	counter = 0;
}
bool CardEight::flag = false;
void CardEight::ReadCardParameters(Grid* pGrid) {
	if (!flag)
	{
		pGrid->GetOutput()->PrintMessage(" prison Price. Enter Valid number: ");
		int PRICE = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		if (PRICE < 0) {
			pGrid->GetOutput()->PrintMessage("Invalid card Price. Enter Valid number: ");
			PRICE = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
			Price = PRICE;
		}
		else Price = PRICE;
	}
	flag = true;
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);
	int ctr = pPlayer->GetCardEightCTR();
	if (ctr == 3) { pPlayer->SetCardEightCTR(0); return; }

	if (ctr == 0) {
	pGrid->GetOutput()->PrintMessage("Card 8 'PRISON', Do you want pay and get out or stay? , Type 'YES' (to get out), 'NO' (to stay)");
		string z = pGrid->GetInput()->GetSrting(pGrid->GetOutput());
		for_each(z.begin(), z.end(), [](char& c)
			{
				c = ::toupper(c);
			});

		if (z == "YES") {
			if (pPlayer->GetWallet() >= Price)
			{
				pPlayer->ChangeWalletAmount(Price);
				counter = 3;
				return;
			}
			else {
				pGrid->GetOutput()->PrintMessage(" Not Enough Money");// pGrid->AdvanceCurrentPlayer(); 
			}
		}
	}
	if (ctr < 3)
	{
		pPlayer->SetCardEightCTR(ctr + 1);
	}

	pGrid->GetOutput()->ClearStatusBar();
}

void CardEight::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << Price << " " << flag << " " << counter << endl;
	}
}

void CardEight::Load(ifstream& Infile, Type obj) {
	if (obj == card) {

		Card::Load(Infile, obj);
		Infile >> Price >> flag >> counter;
	}
}

CardEight::~CardEight()
{
}