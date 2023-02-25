#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}
int InputDiceValue::DiceValue  = 0;
void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter dice value: ");
	DiceValue = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void InputDiceValue::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	bool endGame = pGrid->GetEndGame();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	if (endGame)
	{
		pOut->PrintMessage("Game Ended! Player(" + to_string(pGrid->GetCurrentPlayer()->GetPlayerNumber()) + "), Click to continue...");
		pIn->GetPointClicked(x, y);
	}

	else 
	{
		
		Player* currentPlayer = pGrid->GetCurrentPlayer();

		if (!(currentPlayer->GetCardFour()))
		{
			// 4- Move the currentPlayer using function Move of class player
			currentPlayer->Move(pGrid, DiceValue);
		
		}
		else
		{
			if (currentPlayer->GetCardFourCTR() > 0)
			{
				currentPlayer->SetCardFour(false);
				currentPlayer->SetCardFourCTR(0);
				currentPlayer->setTurnCount(currentPlayer->GetTurnCount() + 1);
			}
			currentPlayer->Move(pGrid, 0);
			currentPlayer->SetCardFourCTR(currentPlayer->GetCardFourCTR() + 1);
		}
		endGame = pGrid->GetEndGame();
		/*currentPlayer->SetCardFour(false);*/
		// 5- Advance the current player number of pGrid
		if(!endGame)
			pGrid->AdvanceCurrentPlayer();
		else
		{
			pOut->PrintMessage("Game Ended! Player(" + to_string(pGrid->GetCurrentPlayer()->GetPlayerNumber()) + ") won!, Click to continue...");
			pIn->GetPointClicked(x, y);
		}

	}

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceValue::~InputDiceValue()
{
}