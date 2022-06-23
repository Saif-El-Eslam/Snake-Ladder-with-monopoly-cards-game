#include "OpenGridAction.h"

#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Cell.h"
#include "Ladder.h"
#include "Snake.h"
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

#include <fstream>


OpenGridAction::OpenGridAction(ApplicationManager * pApp) : Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Enter the File name ");
	FileName = pIn->GetSrting(pOut);
	FileName = FileName + ".txt";
	pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	
	pOut->ClearGridArea();                                                   //to remove eny object in the grid if there is objects Already
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Player * pPlayer = pGrid->GetCurrentPlayer();

		pPlayer->SetturnCount(0);
		pPlayer->SetWallet(100);

		CellPosition  FirstCellpos = CellPosition::GetCellPositionFromNum(1);

		pGrid->UpdatePlayerCell(pPlayer, FirstCellpos);

		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetcurrPlayerNumber(0);                                   // لحد هنا
	
	ifstream FileToOpen(FileName);
	int LaddersNum = 0;
	FileToOpen >> LaddersNum;
	for (int i = 0; i < LaddersNum; i++)
	{
		int Scell, Ecell;
		FileToOpen >> Scell >> Ecell;
		CellPosition Spos(Scell), Epos(Ecell);
		Ladder* L = new Ladder(Spos, Epos);
		pGrid->AddObjectToCell(L);
	}

	int SnakesNum = 0;
	FileToOpen >> SnakesNum;
	for (int i = 0; i < SnakesNum; i++)
	{
		int Scell, Ecell;
		FileToOpen >> Scell >> Ecell;
		CellPosition Spos(Scell), Epos(Ecell);
		Ladder* L = new Ladder(Spos, Epos);
		pGrid->AddObjectToCell(L);
	}

	int CoinSetsNum = 0;
	FileToOpen >> CoinSetsNum;
	for (int i = 0; i < CoinSetsNum; i++)
	{
		int cell, Amount;
		FileToOpen >> cell >> Amount;
		CellPosition pos(cell);
		CoinSet* cs = new CoinSet(pos);
		cs->SetAmount(Amount);
		pGrid->AddObjectToCell(cs);
	}

	int CardsNum = 0;
	FileToOpen >> CardsNum;
	for (int i = 0; i < CardsNum; i++)
	{
		int cardnum;
		FileToOpen >> cardnum;

		if (cardnum == 1) 
		{
			int cell, walletamount;
			FileToOpen >> cell >> walletamount;
			CellPosition Cell(cell);
			DecWalletCard_1* c = new DecWalletCard_1(Cell);
			c->SetwalletAmount(walletamount);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 2)
		{
			int cell, indicator;
			FileToOpen >> cell >> indicator;
			CellPosition Cell(cell);
			NextCard_2* c = new NextCard_2(Cell);
			c->SetnumIndicator(indicator);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 3)
		{
			int cell;
			FileToOpen >> cell;
			CellPosition Cell(cell);
			NextCard_2* c = new NextCard_2(Cell);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 4)
		{
			int cell;
			FileToOpen >> cell;
			CellPosition Cell(cell);
			PreventCard_4* c = new PreventCard_4(Cell);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 5)
		{
			int cell;
			FileToOpen >> cell;
			CellPosition Cell(cell);
			FireCard_5* c = new FireCard_5(Cell);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 6)
		{
			int cell, turns;
			bool EO;
			FileToOpen >> cell >> EO >> turns;
			CellPosition Cell(cell);
			FreezeCard_6* c = new FreezeCard_6(Cell);
			c->SetEvenOrOdd(EO);
			c->SetNumberOfTurns(turns);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 7)
		{
			int cell, Price, Fees;
			FileToOpen >> cell >> Price >> Fees;
			CellPosition Cell(cell);
			MonopolyCard_7* c = new MonopolyCard_7(Cell);
			c->SetPrice(Price);
			c->SetFees(Fees);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 8)
		{
			int cell, Price, Fees;
			FileToOpen >> cell >> Price >> Fees;
			CellPosition Cell(cell);
			MonopolyCard_8* c = new MonopolyCard_8(Cell);
			c->SetPrice(Price);
			c->SetFees(Fees);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 9)
		{
			int cell, Price, Fees;
			FileToOpen >> cell >> Price >> Fees;
			CellPosition Cell(cell);
			MonopolyCard_9* c = new MonopolyCard_9(Cell);
			c->SetPrice(Price);
			c->SetFees(Fees);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 10)
		{
			int cell, Price, Fees;
			FileToOpen >> cell >> Price >> Fees;
			CellPosition Cell(cell);
			MonopolyCard_10* c = new MonopolyCard_10(Cell);
			c->SetPrice(Price);
			c->SetFees(Fees);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 11)
		{
			int cell, Price, Fees;
			FileToOpen >> cell >> Price >> Fees;
			CellPosition Cell(cell);
			MonopolyCard_11* c = new MonopolyCard_11(Cell);
			c->SetPrice(Price);
			c->SetFees(Fees);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 12)
		{
			int cell;
			FileToOpen >> cell;
			CellPosition Cell(cell);
			TakeCityCard_12* c = new TakeCityCard_12(Cell);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 13)
		{
			int cell;
			FileToOpen >> cell;
			CellPosition Cell(cell);
			LoseCityCard_13* c = new LoseCityCard_13(Cell);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 14)
		{
			int cell;
			FileToOpen >> cell;
			CellPosition Cell(cell);
			ReturnMortgagedCard_14* c = new ReturnMortgagedCard_14(Cell);
			pGrid->AddObjectToCell(c);
		}
		else if (cardnum == 15)
		{
			int cell, turns;
			FileToOpen >> cell >> turns;
			CellPosition Cell(cell);
			BenefitAllCard_15* c = new BenefitAllCard_15(Cell);
			c->Setn_turns(turns);
			pGrid->AddObjectToCell(c);
		}

	}


}

OpenGridAction::~OpenGridAction()
{
}