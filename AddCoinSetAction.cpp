#include "AddCoinSetAction.h"
#include "Input.h"
#include "Output.h"

#include "CoinSet.h"


AddCoinSetAction:: AddCoinSetAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddCoinSetAction::ReadActionParameters() 
{
	//  Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//Read the "coin setposition" parameter and set its data member
	pOut->PrintMessage("Click on the position of the CoinSet:- ");
	coinsetPosition = pIn->GetCellClicked();
	
	while (!coinsetPosition.IsValidCell())
	{
		pOut->PrintMessage("InValid Cell, reclick on the position of the new CoinSet:- ");
		coinsetPosition = pIn->GetCellClicked();
	}
	
	int h = coinsetPosition.HCell();
	int v = coinsetPosition.VCell();
	Cell Cell(v, h);

	while (Cell.HasCard() || Cell.HasLadder() || Cell.HasSnake() || Cell.HasCoinSet())
	{
		pOut->PrintMessage("Invalid CoinSet Position, Reclick on Card Position:- ");
		coinsetPosition = pIn->GetCellClicked();
	}

	// Get the CoinSet Amount
	pOut->PrintMessage("Enter the CoinSet Amount:- ");
	coinsetAmount = pIn->GetInteger(pOut);
	while (coinsetAmount <= 0)
	{
		pOut->PrintMessage("you entered INVALID Amount renter the CoinSet Amount:- ");
		coinsetAmount = pIn->GetInteger(pOut);
	}
	// Clear status bar
	pOut->ClearStatusBar();
}

void AddCoinSetAction::Execute()
{
	ReadActionParameters();

	if (coinsetPosition.GetCellNum() == 99 || coinsetPosition.GetCellNum() == 1)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->PrintErrorMessage("Invalid Cell...");

		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
	else
	{
		CoinSet* pCoinSet = new CoinSet(coinsetPosition);

		Grid* pGrid = pManager->GetGrid();

		bool added = pGrid->AddObjectToCell(pCoinSet);

		if (!added)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pCoinSet;
		}
	}
}

AddCoinSetAction::~AddCoinSetAction()
{
}