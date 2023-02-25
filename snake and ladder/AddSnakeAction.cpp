#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp):Action(pApp)
{

}
void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Snake : Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	//if (!(startPos.GetCellNum() > endPos.GetCellNum()) || startPos.HCell() != endPos.HCell() )
	//{
	//	pGrid->PrintErrorMessage("Invalid Snake: Click to continue...");
	//}

	
	pOut->ClearStatusBar();
}
void AddSnakeAction::Execute()
{
	ReadActionParameters();
	int added = -1;
	Grid* pGrid = pManager->GetGrid();
	if (startPos.GetCellNum() != endPos.GetCellNum())
	{
		Snake* pSnake = new Snake(startPos, endPos);
		added = pGrid->AddObjectToCell(pSnake);
	}
	else added = 5;

	// if the GameObject cannot be added
	if (added == 0)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue...");
	}
	else if (added == 2) // if the GameObject is Overlapping
	{
		pGrid->PrintErrorMessage("Error: Overlapping is not allowed! Click to continue...");
	}
	else if (added == 3) // if GameObject intersects with  End of ladder
	{
		pGrid->PrintErrorMessage("Error: Intersection with Ladder! Click to continue...");
	}
	else if (added == 4)	// if GameObject intersects with  End of Snake
	{
		pGrid->PrintErrorMessage("Error: Intersection with Snake! Click to continue...");
	}
	else if (added == 5)	// if the start cell is the end cell
	{
		pGrid->PrintErrorMessage("Error: Same Cell is not allowed! Click to continue...");
	}
}
AddSnakeAction::~AddSnakeAction() {

}