#include "CardOne.h"
#include<fstream>
CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	SetCardNumber(1); // set the inherited cardNumber data member with the card number (1 here)

}
bool CardOne::flag = false;
CardOne::~CardOne(void)
{
}
int CardOne::walletAmount = 0;
void CardOne::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (flag)
		return;
	flag = true;
	pOut->PrintMessage("CardOne: Enter a wallet amount between 0 and 50: ");
	int validAmount = pIn->GetInteger(pOut);
	if (validAmount > 0 && validAmount <= 50)
		walletAmount = validAmount;
	else
	{
		pOut->PrintMessage("Invalid Amount and set to 20, Click to continue...");
		walletAmount = 20;
		int x, y;
		pIn->GetPointClicked(x, y);
	}

	// [ Note ]:
// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
// to be able to perform his Apply() action


// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	Card::Apply(pGrid, pPlayer);
	pPlayer->ChangeWalletAmount(walletAmount);
}
void CardOne::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << this->walletAmount << " " << flag << endl;
	}
}
void CardOne::Load(ifstream& Infile, Type obj) {

	if (obj == card) {
		Card::Load(Infile, obj);
		Infile >> walletAmount >> flag;
	}
}
