#include "FireCard_5.h"
#include "Snake.h"
#include "ladder.h"
#include "Card.h"
#include "CoinSet.h"
#include "fstream"

FireCard_5::FireCard_5 (const CellPosition & pos) :Card(pos)
{
	cardNumber=5;
}

 void FireCard_5::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Player* pCurrentPlayer=pGrid->GetCurrentPlayer();
	CellPosition curPosition=pCurrentPlayer->GetCell()->GetCellPosition();
	int vcell=curPosition.VCell();
	int hcell=curPosition.HCell();

	pPlayer==pGrid->GetCurrentPlayer();

	for (int i = 0; i <= 3; i++)
	{

			pGrid->AdvanceCurrentPlayer();                
			pPlayer=pGrid->GetCurrentPlayer();
		
			CellPosition pos=(pPlayer->GetCell())->GetCellPosition();
			if (vcell==pos.VCell() || hcell==pos.HCell())
			{
				pPlayer->SetWallet(pPlayer->GetWallet()/2);
				pGrid->UpdatePlayerCell(pPlayer ,1);
			}
	}
		
			pGrid->AdvanceCurrentPlayer();                 // to get back to the current player 
			pPlayer=pGrid->GetCurrentPlayer();
}
 void FireCard_5::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void FireCard_5::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum;

	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}

FireCard_5::~FireCard_5(void)
{
}
