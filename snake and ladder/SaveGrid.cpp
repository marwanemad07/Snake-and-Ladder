#include "SaveGrid.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
SaveGrid::SaveGrid(ApplicationManager* pApp) : Action(pApp)
{
}
void SaveGrid::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter file name: ");
	filename = pIn->GetSrting(pOut);
}
void SaveGrid::Execute() {
	SaveGrid::ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	output.open(filename);
	output << Ladder::GetLadderCounter() << endl;

	pGrid->SaveAll(output, ladder);
	output << Snake::getsnakeCounter() << endl;

	pGrid->SaveAll(output, snake);
	output << Card::getCardsCounter() << endl;
	pGrid->SaveAll(output, card);
	pGrid->PrintErrorMessage("save is done");
}

SaveGrid::~SaveGrid()
{
}
