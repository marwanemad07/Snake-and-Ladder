#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}
 
void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters
	/*if (!(startPos.GetCellNum() < endPos.GetCellNum()) || startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Invalid Ladder: Click to continue...");
	}*/

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members

	ReadActionParameters();
	int added = -1;
	// Create a Ladder object with the parameters read from the user
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	/*Ladder * pLadder = new Ladder(startPos, endPos);
	Cell* pCell = pGrid->GetCell(startPos);
	GameObject* pGame = pCell->GetGameObject();*/
	
	if (startPos.GetCellNum() != endPos.GetCellNum())
	{
		Ladder* pLadder = new Ladder(startPos, endPos);
		Cell* pCell = pGrid->GetCell(startPos);
		GameObject* pGame = pCell->GetGameObject();


		// Add the card object to the GameObject of its Cell:
		//bool flag = pGrid->IsOverLapping(pGame);
		added = pGrid->AddObjectToCell(pLadder);
	}
	else added = 5;
	// Add the card object to the GameObject of its Cell:
	//bool flag = pGrid->IsOverLapping(pGame);
		
		// if the GameObject cannot be added
		if (added == 0)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object! Click to continue...");
		}
		else if (added == 2)
		{
			pGrid->PrintErrorMessage("Error: Overlapping is not allowed! Click to continue...");
		}
		else if (added == 3)
		{
			pGrid->PrintErrorMessage("Error: Intersection with Ladder! Click to continue...");
		}
		else if (added == 4)
		{
			pGrid->PrintErrorMessage("Error: Intersection with Snake! Click to continue...");
		}
		else if (added == 5)
		{
			pGrid->PrintErrorMessage("Error: Same Cell is not allowed! Click to continue...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
		
}
