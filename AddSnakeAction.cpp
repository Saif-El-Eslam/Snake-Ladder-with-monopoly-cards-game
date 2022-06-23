#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	while (!startPos.IsValidCell() || !endPos.IsValidCell())
	{
		pOut->PrintMessage("you enterd an Invalid Cell...");

		pOut->PrintMessage("New Snake: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Snake: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
	}

	int hs = startPos.HCell();
	int vs = startPos.VCell();
	Cell Cells(vs, hs);
	if (Cells.HasCard() || Cells.HasLadder() || Cells.HasSnake() || Cells.HasCoinSet())
	{
		pOut->PrintMessage("Invalid Ladder Start Cell, the start cell contains another object! ");
		return;
	}

	int he = endPos.HCell();
	int ve = endPos.VCell();
	Cell Celle(ve, he);
	if (Celle.HasCard() || Celle.HasLadder() || Celle.HasSnake() || Celle.HasCoinSet())
	{
		pOut->PrintMessage("Invalid Ladder end Cell, the end cell contains another object! :- ");
		return;
	}


	if (startPos.VCell() > endPos.VCell() || startPos.HCell() != endPos.HCell())
	{
		pOut->PrintMessage("Invalid, Stert Cell Must be under the end cell in the same column!");
		return;
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Snake * pSnake = new Snake(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

										// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		return;
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}

AddSnakeAction::~AddSnakeAction()
{
}