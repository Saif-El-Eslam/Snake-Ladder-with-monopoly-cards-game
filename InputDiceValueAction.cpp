#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"
#include "Snake.h"
#include "Card.h"
#include "Ladder.h"

#include <time.h> // used to in srand to generate random numbers with different seed


InputDiceValueAction::InputDiceValueAction(ApplicationManager * pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
}

void InputDiceValueAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	int x, y;
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		pOut->PrintMessage("Player" + to_string(pGrid->GetcurrPlayerNumber()) + "is the winner");
		pIn->GetPointClicked(x, y);

		for (int i = 0; i < MaxPlayerCount; i++)
		{
			Player * pPlayer = pGrid->GetCurrentPlayer();

			pPlayer->SetturnCount(0);
			pPlayer->SetWallet(100);

			CellPosition  FirstCellpos = CellPosition::GetCellPositionFromNum(1);

			pGrid->UpdatePlayerCell(pPlayer, FirstCellpos);

			pGrid->AdvanceCurrentPlayer();
		}
		pGrid->SetcurrPlayerNumber(0);

		pOut->ClearStatusBar();
	}
	else
	{
		// -- If not ended, do the following --:

		int diceNumber;
		pOut->PrintMessage("Enter A Dice Number, from 1-6 ");
		diceNumber = pIn->GetInteger(pOut);

		while (diceNumber<1 || diceNumber>6)
		{
			pOut->PrintMessage("Invalid, Enter A Dice Number, from 1-6 ");
			diceNumber = pIn->GetInteger(pOut);
		}


										 // 3- Get the "current" player from pGrid
		Player * pPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
	//	for (int i = 0; i < pPlayer->getpreventtimes(); i++)
	//	{
	//		if (pPlayer->getprevent() == true && (pPlayer->getpreventtimes()) >0)
	//		{
	//			pPlayer->Move(pGrid, 0);
	//			pPlayer->setpreventtimes((pPlayer->getpreventtimes()) - 1);
	//			if (pPlayer->getpreventtimes() == 0)
	//			{
	//				pPlayer->setprevent(false);
	//				pPlayer->setpreventtimes(0);
	//			}
	//		}
	//		else
				pPlayer->Move(pGrid, diceNumber);
	//	}

		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceValueAction::~InputDiceValueAction()
{
}