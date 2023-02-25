#include "CardSeven.h"
#include<fstream>
CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
    SetCardNumber(7);
}
void CardSeven::ReadCardParameters(Grid* pGrid)
{

}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
    Card::Apply(pGrid, pPlayer);
    Player* playerlist[4];
    playerlist[0] = pGrid->GetCurrentPlayer();
    pGrid->AdvanceCurrentPlayer();
    playerlist[1] = pGrid->GetCurrentPlayer();
    pGrid->AdvanceCurrentPlayer();
    playerlist[2] = pGrid->GetCurrentPlayer();
    pGrid->AdvanceCurrentPlayer();
    playerlist[3] = pGrid->GetCurrentPlayer();


    int temp1 = playerlist[1]->GetCell()->GetCellPosition().GetCellNum()
        - playerlist[0]->GetCell()->GetCellPosition().GetCellNum();
    int temp2 = playerlist[2]->GetCell()->GetCellPosition().GetCellNum()
        - playerlist[0]->GetCell()->GetCellPosition().GetCellNum();
    int temp3 = playerlist[3]->GetCell()->GetCellPosition().GetCellNum()
        - playerlist[0]->GetCell()->GetCellPosition().GetCellNum();

    if (temp1 < 0 && temp2 < 0 && temp3 < 0) {
        pGrid->AdvanceCurrentPlayer();
        return;
    }
    if (temp1 < 0) {
        temp1 = 1000;
    }
    if (temp2 < 0) {
        temp2 = 1000;
    }
    if (temp3 < 0) {
        temp3 = 1000;
    }
    int min = min(min(temp1, temp2), temp3);
    //k
//(min == temp1) ? pGrid->UpdatePlayerCell(playerlist[1], CellPosition(1)) : (min == temp2) ? pGrid->UpdatePlayerCell(playerlist[2], CellPosition(1)) : pGrid->UpdatePlayerCell(playerlist[1], CellPosition(1));
    if (min == temp3) {
        if(playerlist[3]->GetCardEightCTR() == 0)
          pGrid->UpdatePlayerCell(playerlist[3], CellPosition(1));
    }
    else {
        if (min == temp2)
            if (playerlist[2]->GetCardEightCTR() == 0)
            pGrid->UpdatePlayerCell(playerlist[2], CellPosition(1));

            else
            {
                if (playerlist[1]->GetCardEightCTR() == 0)
                pGrid->UpdatePlayerCell(playerlist[1], CellPosition(1));
            }
    }
    pGrid->AdvanceCurrentPlayer();

}
void CardSeven::Save(ofstream& OutFile, Type obj) {
    if (obj == card) {
        Card::Save(OutFile, obj);
        OutFile << endl;
    }
}
void CardSeven::Load(ifstream& Infile, Type obj) {
    if (obj == card) {
        Card::Load(Infile, obj);
    }
}
CardSeven::~CardSeven()
{

}