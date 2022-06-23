#include "NewGameAction.h"
#include "Grid.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) :Action(pApp)
{
	Grid* pGrid = pApp->GetGrid();
	Output* pOut = pGrid->GetOutput();
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Player * pPlayer ;								//////
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		
		pPlayer= pGrid->GetCurrentPlayer();
		pPlayer->SetturnCount(0);
		pPlayer->SetWallet(100);
		
		pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(1) );

		pGrid->AdvanceCurrentPlayer();
	}

	
	pGrid->SetcurrPlayerNumber(0);
	pPlayer= pGrid->GetCurrentPlayer();
	pGrid->SetEndGame(false);												//////

	pOut->ClearStatusBar();
	
}


NewGameAction::~NewGameAction()
{
}