#include "CardFive.h"
#include <cmath>
#include<fstream>

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	SetCardNumber(5);
	//justRolledDiceNum = -1;
}

void CardFive::ReadCardParameters(Grid* pGrid)
{

}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	justRolledDiceNum = pPlayer->GetJustRolledDiceNumber();
	newCell = pPlayer->GetCell()->GetCellPosition().GetCellNum() - justRolledDiceNum;
	pGrid->UpdatePlayerCell(pPlayer, newPosition.GetCellPositionFromNum(abs(newCell)));
	Cell* pCell = pPlayer->GetCell();
	pCell = pGrid->GetCurrentPlayer()->GetCell();
	GameObject* pGame = pCell->GetGameObject();
	if (pCell->HasLadder())
		pGame->Apply(pGrid, pPlayer);
	if (pCell->HasSnake())
		pGame->Apply(pGrid, pPlayer);
	if (pCell->HasCard())
		pGame->Apply(pGrid, pPlayer);

	
	pCell = pGrid->GetCurrentPlayer()->GetCell();
	pGame = pCell->GetGameObject();

	if (pCell->HasLadder())
		pGame->Apply(pGrid, pPlayer);
	if (pCell->HasSnake())
		pGame->Apply(pGrid, pPlayer);
	if (pCell->HasCard())
		pGame->Apply(pGrid, pPlayer);

}
void CardFive::Save(ofstream& OutFile, Type obj) {
	if (obj == card) {
		Card::Save(OutFile, obj);
		OutFile << endl;
	}
}
void CardFive::Load(ifstream& Infile, Type obj) {
	if (obj == card) {
		Card::Load(Infile, obj);
	}
}

CardFive::~CardFive()
{
}
