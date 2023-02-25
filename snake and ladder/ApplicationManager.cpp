#include "ApplicationManager.h"
#include"PasteCard.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "AddSnakeAction.h"
#include"CopyCard.h"
#include"CutCard.h"
#include"DeleteGameObject.h"
#include"NewGame.h"
#include"InputDiceValue.h"
#include"DesignModeToolBar.h"
#include"PlayModeToolBar.h"
#include"SaveGrid.h"
#include"OpenGrid.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid* ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;
	case EXIT:
		break;
	case TO_PLAY_MODE:
		pAct = new PlayModeToolBar(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new DesignModeToolBar(this);
		break;

	case COPY_CARD:
		// create an object of AddCardAction here
		pAct = new CopyCard(this);
		break;
	case CUT_CARD:
		// create an object of AddCardAction here
		pAct = new CutCard(this);
		break;
	case PASTE_CARD:
		// create an object of AddCardAction here
		pAct = new PasteCard(this);
		break;
	case DELETE_GAMEOBJECT:
		// create an object of AddCardAction here
		pAct = new DeleteGameObject(this);
		break;
	case NEW_GAME:
		// create an object of AddCardAction here
		pAct = new NewGame(this);
		break;
	case 	INPUT_DICE_VALUE:
		// create an object of AddCardAction here
		pAct = new InputDiceValue(this);
		break;
		///TODO: Add a case for EACH Action type in the Design mode or Play mode
	case SAVED_GRID:
		pAct = new SaveGrid(this);
		break;
	case OPEN_GRID:
		pAct = new OpenGrid(this);
		break;

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
