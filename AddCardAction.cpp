#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"

#include "DecWalletCard_1.h" 
#include "NextCard_2.h"
#include "BackwardCard_3.h"
#include "PreventCard_4.h"
#include "FireCard_5.h"
#include "FreezeCard_6.h"
#include "MonoPolyCard_7.h"
#include "MonoPolyCard_8.h"
#include "MonoPolyCard_9.h"
#include "MonoPolyCard_10.h"
#include "MonoPolyCard_11.h"
#include "TakeCityCard_12.h"
#include "LoseCityCard_13.h"
#include "ReturnMortgagedCard_14.h"
#include "BenefitAllCard_15.h"
AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	Grid *pGrid = pApp->GetGrid();
	Input *pIn = pGrid-> GetInput();
	Output *pOut = pGrid-> GetOutput();
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	
	pOut->PrintMessage("Enter Card Number:- ");
	cardNumber = pIn->GetInteger(pOut);
	while (cardNumber < 1 || cardNumber > 15)
	{
		pOut->PrintMessage("Invalid Card Number, Renter Card Number (1-14):- ");
		cardNumber = pIn->GetInteger(pOut);
	}

	pOut->PrintMessage("click on Card Position:- ");
	cardPosition = pIn->GetCellClicked();
	while (!cardPosition.IsValidCell())
	{
		pOut->PrintMessage("Invalid Card Position, Reclick on Card Position:- ");
		cardPosition = pIn->GetCellClicked();
	}
	
	/*int h = cardPosition.HCell();
	int v = cardPosition.VCell();
	Cell Cell(v, h);

	while (Cell.HasCard() || Cell.HasLadder() || Cell.HasSnake() || Cell.HasCoinSet())
	{
		pOut->PrintMessage("Invalid Card Position, Reclick on Card Position:- ");
		cardPosition = pIn->GetCellClicked();
	}*/

	pOut->ClearStatusBar();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	
	// 2- Read the "cardNumber" parameter and set its data member
	
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	ReadActionParameters();

		Card * pCard ;// will point to the card object type
		switch (cardNumber)
		{
		case 1:
			pCard = new DecWalletCard_1(cardPosition);
			break;
		case 2:
			pCard = new NextCard_2(cardPosition);
			break;
		case 3:
			pCard = new BackwardCard_3(cardPosition);
			break;
		case 4:
			pCard = new PreventCard_4(cardPosition);
			break;
		case 5:
			pCard = new FireCard_5(cardPosition);
			break;
		case 6:
			pCard = new FreezeCard_6(cardPosition);
			break;
		case 7:
			pCard = new MonopolyCard_7(cardPosition);
			break;
		case 8:
			pCard = new MonopolyCard_8(cardPosition);
			break;
		case 9:
			pCard = new MonopolyCard_9(cardPosition);
			break;
		case 10:
			pCard = new MonopolyCard_10(cardPosition);
			break;
		case 11:
			pCard = new MonopolyCard_11(cardPosition);
			break;
		case 12:
			pCard = new TakeCityCard_12(cardPosition);
			break;
		case 13:
			pCard = new LoseCityCard_13(cardPosition);
			break;
		case 14:
			pCard = new ReturnMortgagedCard_14(cardPosition);
			break;
		case 15:
			pCard = new BenefitAllCard_15(cardPosition);
			break;
			// A- Add the remaining cases

		}

		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			// A- We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();
			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->ReadCardParameters(pGrid);
			// C- Add the card object to the GameObject of its Cell:

			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
			bool VCell = pGrid->AddObjectToCell(pCard);

			if (VCell == false)
				pGrid->PrintErrorMessage("Invalid Cell, The Cell already has object! ");

		}

	}
	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction


AddCardAction::~AddCardAction()
{
}
