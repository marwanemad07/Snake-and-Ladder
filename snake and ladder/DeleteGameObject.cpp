#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Cell.h"
#include"Card.h"

DeleteGameObject::DeleteGameObject(ApplicationManager *pApp) :Action(pApp)
{
}
void DeleteGameObject::ReadActionParameters(){
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage(" click on the object cell You want to delete");

	deletePosition = pIn->GetCellClicked();

	if (deletePosition.IsValidCell())

	Delete = pGrid->GetCell(deletePosition);
	
}
void DeleteGameObject::Execute(){
	DeleteGameObject::ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (deletePosition.IsValidCell())
	{

		if (Delete->HasCard() || Delete->HasLadder() || Delete->HasSnake()) {
			pGrid->RemoveObjectFromCell(Delete->GetCellPosition());
			pOut->PrintMessage("successfully deleted");
		}
		else pOut->PrintMessage(" you clicked on empty cell");
	}
	else pOut->PrintMessage(" You have clicked somewhere outside the grid");

}


DeleteGameObject::~DeleteGameObject()
{
}
