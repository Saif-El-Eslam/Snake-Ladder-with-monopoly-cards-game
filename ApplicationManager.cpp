#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "AddCoinSetAction.h"
#include "AddSnakeAction.h"
#include "CopyCardOrCoinsAction.h"
#include "CutCardOrCoinsAction.h"
#include "DeleteGameObjectAction.h"
//#include "ExitAction.h"H
#include "InputDiceValueAction.h"
#include "NewGameAction.h"
#include "OfferMortgageAction.h"
#include "AcceptMortgageAction.h"
#include "OpenGridAction.h"
#include "PasteAction.h"
#include "ReturnMortgageAction.h"
#include "SaveGridAction.h"
#include "SellCityAction.h"
#include "SwitchToDesignModeAction.h"
#include "SwitchToPlayModeAction.h"
#include "RollDiceAction.h"

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

Grid * ApplicationManager::GetGrid() const
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

	case ADD_COIN_SET:
		pAct = new AddCoinSetAction(this);
		break;

	case COPY_CARD_OR_COINS:
		pAct = new CopyCardOrCoinsAction(this);
		break;

	case CUT_CARD_OR_COINS:
		pAct = new CutCardOrCoinsAction(this);
		break;

	case DELETE_GAME_OBJECT:
		pAct = new DeleteGameObjectAction(this);
		break;

	case PASTE:
		pAct = new PasteAction(this);
		break;

	case SAVE_GRID:
		pAct = new SaveGridAction(this);
		break;

	case OPEN_GRID:
		pAct = new OpenGridAction(this);
		break;

	
	case SWITCH_TO_PLAY_MODE:
		//pOut->CreatePlayModeToolBar(); ///TODO: temporary till you made its action class (CHANGE THIS LATTER)
		pAct = new SwitchToPlayModeAction(this); 
		break;

	case EXIT:
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case INPUT_DICE_VALUE:
		pAct = new InputDiceValueAction(this);
		break;

	case OFFER_MORTGAGE:
		// create an object of RollDiceAction here
		pAct = new OfferMortgageAction(this);
		break;

	case ACCEPT_MORTGAGE:
		// create an object of RollDiceAction here
		pAct = new AcceptMortgageAction(this);
		break;

	case RETURN_MORTGAGE:
		// create an object of RollDiceAction here
		pAct = new ReturnMortgageAction(this);
		break;

	case SELL_CITY:
		// create an object of RollDiceAction here
		pAct = new SellCityAction(this);
		break;

	case NEW_GAME:
		// create an object of RollDiceAction here
		pAct = new NewGameAction(this);
		break;

	case SWITCH_TO_DESIGN_MODE:
		//pOut->CreateDesignModeToolBar(); //TODO: temporary till you made its action class (CHANGE THIS LATTER)
		pAct = new SwitchToDesignModeAction(this);
		break;
	case Play_EXIT:
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
