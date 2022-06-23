#include "CutCardOrCoinsAction.h"

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

CutCardOrCoinsAction::CutCardOrCoinsAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void CutCardOrCoinsAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the Card or the Coin Set that you want to copy... ");
	CuttedPos = pIn->GetCellClicked();


	pOut->ClearStatusBar();
}

void CutCardOrCoinsAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	Card* pCard = pGrid->CopyCard(CuttedPos);
	CoinSet* pCoinSet = pGrid->CopyCoinSet(CuttedPos);

	if (pCard)
	{
		pGrid->SetClipboardCard(pCard);
		pGrid->RemoveObjectFromCell(CuttedPos);
	}
	else if (pCoinSet)
	{
		pGrid->SetClipboardCoinSet(pCoinSet);
		pGrid->RemoveObjectFromCell(CuttedPos);
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid, there is no Card or CoinSet to Cut in this cell...");
	}
}

CutCardOrCoinsAction::~CutCardOrCoinsAction()
{
}