#include "OpenGrid.h"
#include"Ladder.h"

OpenGrid::OpenGrid(ApplicationManager* pApp) : Action(pApp)
{
}
void OpenGrid::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter file name");
	filename = pIn->GetSrting(pOut);
	input.open(filename);
	pOut->ClearStatusBar();
}
void OpenGrid::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	GameObject* pObj;
	CellPosition pos;
	pGrid->deleteALL();
	for (int i = 0; i < 4; i++) {
		pGrid->GetCurrentPlayer()->MoveToSpecificCell(pGrid, 1);
		pGrid->GetCurrentPlayer()->setTurnCount(0);
		pGrid->GetCurrentPlayer()->SetWallet(100);
		pGrid->AdvanceCurrentPlayer();
	}

	if (pGrid->GetCurrentPlayer()->GetPlayerNumber() == 3) {
		pGrid->AdvanceCurrentPlayer();
	}
	else if (pGrid->GetCurrentPlayer()->GetPlayerNumber() == 2) {
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
	}
	else if (pGrid->GetCurrentPlayer()->GetPlayerNumber() == 1) {
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();


	}
	pGrid->GetCurrentPlayer()->setTurnCount(0);
	int laddernum, snakenum, cardnum;
	input >> laddernum;
	for (int i = 0; i < laddernum; i++) {
		pObj = new Ladder(pos.GetCellPositionFromNum(1), pos.GetCellPositionFromNum(1));
		pObj->Load(input, ladder);
		pGrid->AddObjectToCell(pObj);
	}
	input >> snakenum;
	for (int i = 0; i < snakenum; i++) {
		pObj = new Snake(pos.GetCellPositionFromNum(1), pos.GetCellPositionFromNum(1));
		pObj->Load(input, snake);
		pGrid->AddObjectToCell(pObj);
	}
	input >> cardnum;
	int NumOfCard;
	for (int i = 0; i < cardnum; i++) {
		input >> NumOfCard;
		switch (NumOfCard)
		{
		case 1:
			pObj = new CardOne(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 2:
			pObj = new CardTwo(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 3:
			pObj = new CardThree(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 4:
			pObj = new CardFour(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 5:
			pObj = new CardFive(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 6:
			pObj = new CardSix(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 7:
			pObj = new CardSeven(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 8:
			pObj = new CardEight(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 9:
			pObj = new CardNine(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 10:
			pObj = new CardTen(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 11:
			pObj = new CardEleven(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		case 12:
			pObj = new CardTwelve(pos.GetCellPositionFromNum(1));
			pObj->Load(input, card);
			pGrid->AddObjectToCell(pObj);
			break;
		}


	}
	pOut->PrintMessage("Load is Done ");
}

OpenGrid::~OpenGrid()
{
}
