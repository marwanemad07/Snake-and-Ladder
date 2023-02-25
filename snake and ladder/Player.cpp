#include "Player.h"
#include "GameObject.h"
#include <algorithm>

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	CardEightCTR = 0;
	IceHurt = false;
	usedIce = false;
	AbilitiesCTR = 0;
	CardFourAbility = false;
	cardFourCTR = 0;
	posioned = false;
	posionCTR = 0;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	// Make any needed validations
	if (wallet >= 0)
		this->wallet = wallet;
	// should write else? or let wallet 
	if (wallet < 0)
		this->wallet = 0;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::setTurnCount(int num) {
	turnCount = ((num >= 0) ? num : 0);
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(GetCell()->GetCellPosition(), GetPlayerNumber(), playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(GetCell()->GetCellPosition(), GetPlayerNumber(), cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (posioned)
	{
		diceNumber -= 1;
		SetJustRolledDiceNumber(diceNumber);
		if (posionCTR == 5)
		{
			posioned = false;
			posionCTR = 0;
		}
		posionCTR++;
	}
	else SetJustRolledDiceNumber(diceNumber);

	if (GetCardEightCTR() == 0)
	{
		//Card Four
	/*	if (CardFourAbility)
		{
			SetCardFour(false);
			turnCount++;
			return;
		}*/
		if (GetWallet() < 1) // Check if the player has coins in the wallet
		{
			if (GetTurnCount() < 2)
				turnCount++;
			else
			{
				IncreamentWalletAmount(diceNumber);
			}
			return;
		}
		// == Here are some guideline steps (numbered below) to implement this function ==


		// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
		if (GetTurnCount() < 2) // less than 2 ( see pdf example)	
			turnCount++;

		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		else {
			pOut->PrintMessage("Do you want to charge your wallet or start attacking? , Type '1' (for Wallet) or '2'(for Attacking) ");

			// 1 -> Wallet 
			// 2 -> Attacking

			int input = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

			if (input == 1)
			{
				IncreamentWalletAmount(diceNumber);
				turnCount = 0;
				return;
			}
			else if (input == 2) {
				pOut->PrintMessage("Which ability you would like to use?, Type '1' (for Lightning), '2' (for Ice) , '3' (for Fire) , '4' (for Posion)");

				// 1 -> Lightning
				// 2 -> Ice
				// 3 -> Fire
				// 4 -> Posion

				int input2 = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

				switch (input2)
				{
				case 1:
					Lightining(pGrid);
					break;
				case 2:
					Ice(pGrid);
					break;
				case 3:
					Fire(pGrid);
					break;
				case 4:
					Poison(pGrid);
					break;
				default:
					break;
				}

				turnCount = 0;
				return;
			}
		}
		// 3- Set the justRolledDiceNum with the passed diceNumber

		// 4- Get the player current cell position, say "pos", and add it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"
		Cell* pCell = GetCell();
		CellPosition pos = pCell->GetCellPosition(); // is there any problem here! using new object? ask TA
		int newCellNumber = pos.GetCellNum() + diceNumber;
		if (newCellNumber > 99)
			newCellNumber = 99;
		pos = pos.GetCellPositionFromNum(newCellNumber);
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

		pGrid->UpdatePlayerCell(this, pos); // Is there any problem in using (this)

		// 6- Apply() the game object of the reached cell (if any)
		pCell = pGrid->GetCurrentPlayer()->GetCell();
		GameObject* pGame = pCell->GetGameObject();
		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		GameObject* pPrevGame = NULL;
		while ((pCell->HasLadder() || pCell->HasSnake() || pCell->HasCard()) && pGame != pPrevGame)
		{
			pPrevGame = pGame;
			if (pCell->HasLadder())
				pGame->Apply(pGrid, this);
			if (pCell->HasSnake())
				pGame->Apply(pGrid, this);
			if (pCell->HasCard())
				pGame->Apply(pGrid, this);
			pCell = pGrid->GetCurrentPlayer()->GetCell();
			pGame = pCell->GetGameObject();
		}
		newCellNumber = pCell->GetCellPosition().GetCellNum();

		if (newCellNumber == 99)
			pGrid->SetEndGame(true);
	}
	else
	{
		GameObject* pGame = pCell->GetGameObject();
		if (pCell->HasCard())
			pGame->Apply(pGrid, this);
	}
	/*
	if (FireDeductCTR > 0 && FireDeductCTR < 3)
	{
		this->ChangeWalletAmount(20);
		FireDeductCTR++;
	}

	if (FireDeductCTR >= 3) FireDeductCTR = 0;*/

}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::ChangeWalletAmount(int walletAmount)
{
	SetWallet(GetWallet() - walletAmount);
}
int Player::GetPlayerNumber() const
{
	return playerNum;
}
void Player::IncreamentWalletAmount(int diceNumber)
{
	SetWallet(GetWallet() + 10 * diceNumber);
}
void Player::SetJustRolledDiceNumber(int diceNumber)
{
	justRolledDiceNum = diceNumber;
}
void Player::MoveToSpecificCell(Grid* pGrid, int CellNumber)
{
	CellPosition pos(CellNumber);

	pGrid->UpdatePlayerCell(this, pos);
	pCell = pGrid->GetCurrentPlayer()->GetCell();
	GameObject* pGame = pCell->GetGameObject();
	if (pCell->HasLadder())
		pGame->Apply(pGrid, this);
	if (pCell->HasSnake())
		pGame->Apply(pGrid, this);
	if (pCell->HasCard())
		pGame->Apply(pGrid, this);
}

void Player::Ice(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int toPlayer, choosenPlayer;
	do
	{
		pOut->PrintMessage("Enter a player Number: ");
		choosenPlayer = pIn->GetInteger(pOut);
		if (choosenPlayer == this->GetPlayerNumber())
			pOut->PrintMessage("you can't hurt yourself");

	} while (choosenPlayer == GetPlayerNumber());
	toPlayer = choosenPlayer - GetPlayerNumber();
	if (toPlayer < 0) toPlayer += 4;
	while (toPlayer--)
	{
		pGrid->AdvanceCurrentPlayer();
	}

	Player* pPlayer = pGrid->GetCurrentPlayer();
	string playerNumber = to_string(pPlayer->GetPlayerNumber());
	pGrid->GetOutput()->PrintMessage("Now player 'FREEZED' (" + playerNumber + ") not able to move next round ");

	pPlayer->SetCardFour(true);
	while (this->GetPlayerNumber() != pGrid->GetCurrentPlayer()->GetPlayerNumber()) {
		pGrid->AdvanceCurrentPlayer();
	}
}

void Player::Fire(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int toPlayer, choosenPlayer;
	do
	{
		pOut->PrintMessage("Enter a player Number: ");
		choosenPlayer = pIn->GetInteger(pOut);
		if (choosenPlayer == this->GetPlayerNumber())
			pOut->PrintMessage("you can't hurt yourself");

	} while (choosenPlayer == GetPlayerNumber());
	toPlayer = choosenPlayer - GetPlayerNumber();
	if (toPlayer < 0) toPlayer += 4;
	while (toPlayer--)
	{
		pGrid->AdvanceCurrentPlayer();
	}
	Player* pPlayer = pGrid->GetCurrentPlayer();

	pPlayer->ChangeWalletAmount(60);
	while (this->GetPlayerNumber() != pGrid->GetCurrentPlayer()->GetPlayerNumber()) {
		pGrid->AdvanceCurrentPlayer();
	}
}

void Player::Poison(Grid* pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	int toPlayer, choosenPlayer;
	do
	{
		pOut->PrintMessage("Enter a player Number: ");
		choosenPlayer = pIn->GetInteger(pOut);
		if (choosenPlayer == this->GetPlayerNumber())
			pOut->PrintMessage("you can't hurt yourself");

	} while (choosenPlayer == GetPlayerNumber());
	toPlayer = choosenPlayer - GetPlayerNumber();
	if (toPlayer < 0) toPlayer += 4;
	while (toPlayer--)
	{
		pGrid->AdvanceCurrentPlayer();
	}
	pOut->PrintMessage("Poisoned");
	Player* player = pGrid->GetCurrentPlayer();

	player->SetPosioned(true);
	player->SetPosionCTR(0);
	while (this->GetPlayerNumber() != pGrid->GetCurrentPlayer()->GetPlayerNumber()) {
		pGrid->AdvanceCurrentPlayer();
	}
}

void Player::Lightining(Grid* pGrid) {
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Lighting Strike");
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetCurrentPlayer()->ChangeWalletAmount(20);
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetCurrentPlayer()->ChangeWalletAmount(20);
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetCurrentPlayer()->ChangeWalletAmount(20);
	pGrid->AdvanceCurrentPlayer();

}

void Player::SetCardEightCTR(int ctr)
{
	CardEightCTR = ctr;
}

int Player::GetCardEightCTR() const
{
	return CardEightCTR;
}

void Player::SetCardFour(bool flag)
{
	CardFourAbility = flag;
}

int Player::GetJustRolledDiceNumber()const
{
	return justRolledDiceNum;
}

void Player::SetIceHurt(bool ice)
{
	IceHurt = ice;
}

bool Player::GetIceHurt() const
{
	return IceHurt;
}

bool Player::GetCardFour() {
	return CardFourAbility;
}


void Player::SetCardFourCTR(int value) {
	cardFourCTR = value;
}

int Player::GetCardFourCTR()
{
	return cardFourCTR;
}

void Player::SetPosioned(bool posion)
{
	posioned = posion;
}
void Player::SetPosionCTR(int value)
{
	posionCTR = value;
}
bool Player::GetPosioned()
{
	return posioned;
}
int Player::GetPosionCTR()
{
	return posionCTR;
}