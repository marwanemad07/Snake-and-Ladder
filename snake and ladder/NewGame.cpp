#include "NewGame.h"
#include"Grid.h"
#include"Player.h"

NewGame::NewGame(ApplicationManager *pApp) :Action(pApp)
{

}
void NewGame::ReadActionParameters(){

}
void NewGame::Execute(){
	pManager->GetGrid()->GetOutput()->PrintMessage(" NEW GAME ");
	
	Grid*pGrid = pManager->GetGrid();
	for (int i = 0; i < 4; i++){
		pGrid->GetCurrentPlayer()->MoveToSpecificCell(pGrid, 1);
		pGrid->GetCurrentPlayer()->setTurnCount(0);
		pGrid->GetCurrentPlayer()->SetWallet(100);
		pGrid->GetCurrentPlayer()->SetCardEightCTR(0);
		pGrid->AdvanceCurrentPlayer();
	}

	if (pGrid->GetCurrentPlayer()->GetPlayerNumber() == 3){
		pGrid->AdvanceCurrentPlayer();
	}
	else if (pGrid->GetCurrentPlayer()->GetPlayerNumber() == 2){
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
	}
	else if (pGrid->GetCurrentPlayer()->GetPlayerNumber() == 1){
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
		pGrid->AdvanceCurrentPlayer();
		

	}
		pGrid->GetCurrentPlayer()->setTurnCount(0);

	//Cards to NULL
	pGrid->SetEndGame(false);
	nine->deleteOwner();	
	Ten->deleteOwner();
	Eleven->deleteOwner();
}

NewGame::~NewGame()
{
}
