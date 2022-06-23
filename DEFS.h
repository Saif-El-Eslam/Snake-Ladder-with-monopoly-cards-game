#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_COIN_SET,
	ADD_CARD,		// Add Card Action	
	COPY_CARD_OR_COINS,
	CUT_CARD_OR_COINS,
	PASTE,
	DELETE_GAME_OBJECT,
	SAVE_GRID,
	OPEN_GRID,
	SWITCH_TO_PLAY_MODE,// Go to Play Mode
	EXIT,			// Exit Application
		

	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	INPUT_DICE_VALUE,
	OFFER_MORTGAGE,
	ACCEPT_MORTGAGE,
	RETURN_MORTGAGE,
	SELL_CITY,
	NEW_GAME,
	SWITCH_TO_DESIGN_MODE,	// Go to Design Mode
	Play_EXIT,
	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif