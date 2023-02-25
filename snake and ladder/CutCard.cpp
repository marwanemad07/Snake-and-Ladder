#include "CutCard.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Cell.h"
#include"Card.h"
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


CutCard::CutCard(ApplicationManager* pApp) :Action(pApp)
{
}
void CutCard::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage(" click on the source cell You want to cut");

	CellPosition cardPosition = pIn->GetCellClicked();
	
	
	if (cardPosition.IsValidCell())
	{
		Cut = pGrid->GetCell(cardPosition);

		if (Cut->HasCard())
		{

			Card* pCard = NULL;

			switch (Cut->HasCard()->GetCardNumber())
			{
			case 1:
				pCard = new CardOne(cardPosition);
				break;

				// A- Add the remaining cases
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
			pGrid->SetClipboard(pCard);
			pGrid->RemoveObjectFromCell(Cut->GetCellPosition());
		}
	else pOut->PrintMessage(" try again later");
	}
	else pOut->PrintMessage(" You have clicked somewhere outside the grid");
	pOut->ClearStatusBar();
}

void CutCard::Execute() {
	CutCard::ReadActionParameters();
	pManager->GetGrid()->GetOutput()->PrintMessage(" click on Paste");


}
CutCard::~CutCard()
{
}