#include "CopyCardOrCoinsAction.h"

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


CopyCardOrCoinsAction::CopyCardOrCoinsAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void CopyCardOrCoinsAction :: ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the Card or the Coin Set that you want to copy... ");
	CopiedPos = pIn->GetCellClicked();

	
	pOut->ClearStatusBar();
}

void CopyCardOrCoinsAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	Card* pCard = pGrid->CopyCard(CopiedPos);
	CoinSet* pCoinSet = pGrid->CopyCoinSet(CopiedPos);

	if (pCard)
	{
		pGrid->SetClipboardCard(pCard);
	}
	else if(pCoinSet)
	{
		pGrid->SetClipboardCoinSet(pCoinSet);
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid, there is no Card or CoinSet to Copy in this cell...");
	}
}

CopyCardOrCoinsAction:: ~CopyCardOrCoinsAction()
{
}