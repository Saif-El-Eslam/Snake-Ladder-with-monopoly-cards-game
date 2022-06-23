#include "PasteAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CoinSet.h"
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



PasteAction::PasteAction(ApplicationManager * pApp) : Action(pApp)
{

}

void PasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager -> GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("click on the cell that you want to paste the Card or the CoinSet in");

	CellPos = pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Card* pCard = pGrid->GetClipboardCard();
	CoinSet* pCoinSet = pGrid->GetClipboardCoinSet();
	
	
	if (pCard==NULL && pCoinSet==NULL)
	{
		pGrid->PrintErrorMessage("there is no cord or coin Set to paste!");
	}
	else
	{
		if (pCard)
		{
			pCard->setPosition(CellPos);
			bool c = pGrid->AddObjectToCell(pCard);
			
			if (c == false)
				pGrid->PrintErrorMessage("Invalid, there is an object in this cell..");
			else
				pCard->Draw(pOut);
		
		}
		if (pCoinSet)
		{
			pCoinSet->setPosition(CellPos);
			bool cs = pGrid->AddObjectToCell(pCoinSet);

			if (cs == false)
				pGrid->PrintErrorMessage("Invalid, there is an object in this cell..");
			else
			{
				pCoinSet->Draw(pOut);
			}
		}
	}

	pOut->ClearStatusBar();
}

PasteAction::~PasteAction()
{
}