#include "DeleteGameObjectAction.h"

#include "Card.h"
#include "Snake.h"
#include "Ladder.h"
#include "CoinSet.h"



DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the Game Object that you want to Delete... ");
	DeletedPos = pIn->GetCellClicked();


	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pGrid->RemoveObjectFromCell(DeletedPos);
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}