#include "CardTwelve.h"
#include<fstream>



CardTwelve::CardTwelve(const CellPosition& pos) :Card(pos)
{
	cardNumber = 12;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	int counter = 0;
	Player* playerlist[4];
	playerlist[0] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	playerlist[1] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	playerlist[2] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	playerlist[3] = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	Player* min = playerlist[1];
	for (int i = 1; i < 4; i++) {
		if (playerlist[i]->GetWallet() < min->GetWallet()) {
			min = playerlist[i];
		}
	}
	if (pPlayer == nine->getOwner() && pPlayer == ten->getOwner() && pPlayer == eleven->getOwner()) {
		if ((nine->getCardprice() > ten->getCardprice()) && (nine->getCardprice() > eleven->getCardprice())) {
			nine->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 9 )");
		}
		else if ((ten->getCardprice() > nine->getCardprice()) && (ten->getCardprice() > eleven->getCardprice())) {
			ten->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 10 )");
		}
		else if ((eleven->getCardprice() > nine->getCardprice()) && (eleven->getCardprice() > ten->getCardprice())) {
			eleven->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 11 )");
		}
	}
	else if (pPlayer == nine->getOwner() && pPlayer == ten->getOwner()) {
		if (nine->getCardprice() > ten->getCardprice()) {
			nine->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 9 )");
		}
		else{
			ten->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 10 )");
		}
		}
	else if (pPlayer == nine->getOwner() && pPlayer == eleven->getOwner()) {
		if (nine->getCardprice() > eleven->getCardprice()) {
			nine->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 9 )");
		}
		else {
			eleven->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 11 )");
		}
	}
	else if (pPlayer == ten->getOwner() && pPlayer == eleven->getOwner()) {
		if (ten->getCardprice() > eleven->getCardprice()) {
			ten->setOwner(min);
			pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 10 )");
		}
		else eleven->setOwner(min);
		pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 11 )");
	}
	else if (pPlayer == nine->getOwner()){
		nine->setOwner(min);
		pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 9 )");
	}
	else if (pPlayer == ten->getOwner()){
		ten->setOwner(min);
		pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 10 )");
	}
	else if (pPlayer == eleven->getOwner()){
		eleven->setOwner(min);
		pGrid->PrintErrorMessage("Now player Num (" + to_string(min->GetPlayerNumber()) + ") is the owner of card ( 11 )");
	}




}
void CardTwelve::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << endl;
	}
}
void CardTwelve::Load(ifstream& Infile, Type obj) {
	if (obj == card) {
		Card::Load(Infile, obj);
	}
}
CardTwelve::~CardTwelve()
{
}