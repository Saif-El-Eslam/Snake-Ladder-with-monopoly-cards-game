#include "OfferMortgageAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"

#include "MonopolyCard_7.h"
#include "MonopolyCard_8.h"
#include "MonopolyCard_9.h"
#include "MonopolyCard_10.h"
#include "MonopolyCard_11.h"


OfferMortgageAction::OfferMortgageAction(ApplicationManager * pApp) : Action(pApp)
{
}

void OfferMortgageAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	Player* pPlayer = pGrid->GetCurrentPlayer();
	Player* player[5];
	MonopolyCard_7* Mono7=NULL;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 7));
		if (pCard != NULL)
			Mono7 = dynamic_cast<MonopolyCard_7*>(pCard);
		break;
	}
	player[0] = Mono7->getOwner();
	MonopolyCard_8* Mono8=NULL;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 8));
		if (pCard != NULL)
			Mono8 = dynamic_cast<MonopolyCard_8*>(pCard);
		break;
	}
	player[1] = Mono8->getOwner();
	MonopolyCard_9* Mono9=NULL;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 9));
		if (pCard != NULL)
			Mono9 = dynamic_cast<MonopolyCard_9*>(pCard);
		break;
	}
	player[2] = Mono9->getOwner();
	MonopolyCard_10* Mono10=NULL;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 10));
		if (pCard != NULL)
			Mono10 = dynamic_cast<MonopolyCard_10*>(pCard);
		break;
	}
	player[3] = Mono10->getOwner();
	MonopolyCard_11* Mono11=NULL;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 11));
		if (pCard != NULL)
			Mono11 = dynamic_cast<MonopolyCard_11*>(pCard);
		break;
	}
	player[4] = Mono11->getOwner();
	int sOwned = 0;

	for (int i = 0; i < 5; i++)
	{
		if (player[i] == pPlayer)
			sOwned++;
	}
	int* OCities = new int[sOwned];
	int n=0;
	
	for (int i = 0; i < 5; i++)
	{
		if (player[i] == pPlayer)
		{
			OCities[n] = (i+7);
			n++;
		}
	}

	pOut->PrintMessage("Enter the Number of the cities that you want to Offer for Mortgage ");
	Size=pIn->GetInteger(pOut);
	while (Size > sOwned || Size < 0)
	{
		pOut->PrintMessage("Invalid, Renter the Number of the cities that you want to Offer for Mortgage ");
		Size = pIn->GetInteger(pOut);
	}
	Cities = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		pOut->PrintMessage("Enter the City Number");
		Cities[i] = pIn->GetInteger(pOut);
		int Found=0;
		for (int j = 0; j < sOwned; j++)
		{
			if (Cities[i] == OCities[j] )
				Found++;
		}
		while (Found <= 0)
		{
			pOut->PrintMessage("Invalid Number, Enter a valid number for the city ...");
			Cities[i] = pIn->GetInteger(pOut);
			int Found = 0;
			for (int j = 0; j < sOwned; j++)
			{
				if (Cities[i] == OCities[j])
					Found++;
			}
		}
	}
	pOut->ClearStatusBar();

}

void OfferMortgageAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	Player* pPlayer = pGrid->GetCurrentPlayer();
	MonopolyCard_7* Mono7;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 7));
		if (pCard != NULL)
			Mono7 = dynamic_cast<MonopolyCard_7*>(pCard);
		break;
	}
	MonopolyCard_8* Mono8;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 8));
		if (pCard != NULL)
			Mono8 = dynamic_cast<MonopolyCard_8*>(pCard);
		break;
	}
	MonopolyCard_9* Mono9;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 9));
		if (pCard != NULL)
			Mono9 = dynamic_cast<MonopolyCard_9*>(pCard);
		break;
	}
	MonopolyCard_10* Mono10;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 10));
		if (pCard != NULL)
			Mono10 = dynamic_cast<MonopolyCard_10*>(pCard);
		break;
	}
	MonopolyCard_11* Mono11;
	for (int i = 2; i<100; i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard = (pGrid->GetCardPointer(Cell_Position, 11));
		if (pCard != NULL)
			Mono11 = dynamic_cast<MonopolyCard_11*>(pCard);
		break;
	}

	for (int i = 0; i < Size; i++)
	{
		if (Cities[i] == 7)
		{
			Mono7->SetOffered(true);
		}
		if (Cities[i] == 8)
		{
			Mono8->SetOffered(true);
		}
		if (Cities[i] == 9)
		{
			Mono9->SetOffered(true);
		}
		if (Cities[i] == 10)
		{
			Mono10->SetOffered(true);
		}
		if (Cities[i] == 11)
		{
			Mono11->SetOffered(true);
		}


	}

}

OfferMortgageAction::~OfferMortgageAction()
{
}