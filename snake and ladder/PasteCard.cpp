#include "PasteCard.h"
#include "Input.h"
#include"Card.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

PasteCard::PasteCard(ApplicationManager *pApp) :Action(pApp)
{
}
void PasteCard::ReadActionParameters(){
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


}
void PasteCard::Execute(){
	
	pManager->GetGrid()->GetOutput()->PrintMessage(" click on the cell you want to paste to");
	Card * pCard = NULL;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->GetClipboard() == NULL){
		pGrid->PrintErrorMessage(" You Have copied an Empty Cell");
		return;
	}

	cardPosition=pIn->GetCellClicked();
	switch (pGrid->GetClipboard()->GetCardNumber())
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2: pCard = new CardTwo(cardPosition);
		break;

	case 3:
		pCard = new CardThree(cardPosition);
		break;

	case 4:
		pCard = new CardFour(cardPosition);
		break;

	case 5:
		pCard = new CardFive(cardPosition);
		break;

	case 6:
		pCard = new CardSix(cardPosition);
		break;

	case 7:
		pCard = new CardSeven(cardPosition);
		break;

	case 8:
		pCard = new CardEight(cardPosition);
		break;

	case 9:
		pCard = new CardNine(cardPosition);
		break;

	case 10:
		pCard = new CardTen(cardPosition);
		break;

	case 11:
		pCard = new CardEleven(cardPosition);
		break;

	case 12:
		pCard = new CardTwelve(cardPosition);
		break;
	}
	 
	 bool added = pGrid->AddObjectToCell(pCard);
	 if (!added)
		 pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");



}

PasteCard::~PasteCard()
{
}
