#include "CardNine.h"
#include <string>
#include <algorithm>
#include"Grid.h"
#include<fstream>
CardNine::CardNine(const CellPosition& pos) :Card(pos)
{
	SetCardNumber(9);
}
int CardNine::getCardprice() {
	return CardPrice;
}
void CardNine::ReadCardParameters(Grid* pGrid) {
	if (flag)return;
	pGrid->GetOutput()->PrintMessage(" card Price. Enter Valid number: ");

	int cardPrice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	if (cardPrice <= 0)
	{
		pGrid->GetOutput()->PrintMessage("Invalid card Price. Enter Valid number: ");
		CardPrice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	}
	else
	{
		CardPrice = cardPrice;
	}
	pGrid->GetOutput()->PrintMessage(" Fees Price. Enter Valid number: ");
	int fees = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	if (fees <= 0) {

		pGrid->GetOutput()->PrintMessage("Invalid card Fees. Enter Valid number: ");
		Fees = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	}
	else
	{
		Fees = fees;
	}
	flag = true;

}
void CardNine::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);
	if (buy) {
		pGrid->GetOutput()->PrintMessage(" Do you want to buy this Card? y/n");
		string answer = pGrid->GetInput()->GetSrting(pGrid->GetOutput());
		for_each(answer.begin(), answer.end(), [](char& c) {

			c = ::toupper(c);
			});

		if (answer == "Y") {
			if (pPlayer->GetWallet() >= CardPrice) {
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				setOwner(pPlayer);
				buy = false;
				string x = to_string(pPlayer->GetPlayerNumber());
				pGrid->GetOutput()->PrintMessage("Now You player num (" + x + ") is the owner");
			}
			else { pGrid->GetOutput()->PrintMessage(" Not Enough Money"); return; }
		}
		else return;
	}
	else {
		if (pPlayer == owner) { pGrid->GetOutput()->PrintMessage("Welcome sir"); return; }
		else {
			string ownerNum = to_string(owner->GetPlayerNumber());
			pGrid->GetOutput()->PrintMessage("Now You are in palyer (" + ownerNum + ") card");
			pPlayer->ChangeWalletAmount(Fees);
			owner->SetWallet(owner->GetWallet() + Fees);
		}


	}

}
Player* CardNine::getOwner() {
	return owner;
}
void CardNine::setOwner(Player* z) {
	owner = z;

}
void CardNine::deleteOwner() {
	if (owner != NULL) {
		Player* temp = NULL;
		owner = temp;
		buy = true;
	}
}
void CardNine::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << CardPrice << " " << Fees << " " << flag << " " << buy << endl;
	}
}
void CardNine::Load(ifstream& Infile, Type obj) {
	if (obj == card) {
		Card::Load(Infile, obj);
		Infile >> CardPrice >> Fees >> flag >> buy;
	}
}
bool CardNine::flag = false;
bool CardNine::buy = true;
Player* CardNine::owner = NULL;
int CardNine::CardPrice = 0;
int CardNine::Fees = 0;
CardNine::~CardNine()
{
}