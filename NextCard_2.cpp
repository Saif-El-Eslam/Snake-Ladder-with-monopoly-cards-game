#include "NextCard_2.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CoinSet.h"
#include "fstream"

NextCard_2::NextCard_2(const CellPosition & pos)
	:Card(pos)
{
	cardNumber = 2;
}

void NextCard_2::ReadCardParameters(Grid * pGrid)
{
	Input* input=pGrid->GetInput(); 
	Output* output=pGrid->GetOutput();
		pGrid->PrintErrorMessage("New Next Crad: Enter the type of the nect object to move to --- 1 for Ladder  2 for Snake  3 for CoinSet  4 fro Crad...");
	int typenum=input->GetInteger(output);
	while (typenum<1 || typenum>4)
	{
		pGrid->PrintErrorMessage("Invalid, Enter only one of the boject's numbers");
	}
	numIndicator=typenum;
	 output->ClearStatusBar();
}
void NextCard_2::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition currentpos =pPlayer->GetCell()->GetCellPosition();
	 if (numIndicator==1)
	 {
     Ladder* nextladder=pGrid->GetNextLadder(currentpos);
	 CellPosition nextpos=nextladder->GetPosition();
	 pGrid->UpdatePlayerCell(pPlayer,nextpos);
	 nextladder->Apply(pGrid,pPlayer);
	 }
	 if (numIndicator==2)
	 {
	 Snake* nextsnake=pGrid->GetNextSnake(currentpos);
	 CellPosition nextpos=nextsnake->GetPosition();
	 pGrid->UpdatePlayerCell(pPlayer,nextpos);
	 nextsnake->Apply(pGrid,pPlayer);
	 }
	 if (numIndicator==3)
	 {
	 Card* nextcard=pGrid->GetNextCard(currentpos);
	 CellPosition nextpos=nextcard->GetPosition();
	 pGrid->UpdatePlayerCell(pPlayer,nextpos);
	 nextcard->Apply(pGrid,pPlayer);
	 }
	 if (numIndicator==4)
	 {
     CoinSet* nextcoinset=pGrid->GetNextCoinSet(currentpos);
	 CellPosition nextpos=nextcoinset->GetPosition();
	 pGrid->UpdatePlayerCell(pPlayer,nextpos);
	 nextcoinset->Apply(pGrid,pPlayer);
	 }

}
void NextCard_2::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << numIndicator << endl;
	}
}

void NextCard_2::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum, ind;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum >> ind;

	numIndicator = ind;
	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}

void NextCard_2::SetnumIndicator(int x)
{
	numIndicator = x;
}

NextCard_2::~NextCard_2()
{
}
