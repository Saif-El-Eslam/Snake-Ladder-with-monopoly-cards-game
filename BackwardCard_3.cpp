#include "BackwardCard_3.h"
#include "Snake.h"
#include "ladder.h"
#include "Card.h"
#include "CoinSet.h"
#include "fstream"
BackwardCard_3::BackwardCard_3(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 3;
}
void BackwardCard_3::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
		pPlayer=pGrid->GetCurrentPlayer();
		int amount=pPlayer->GetjustRolledDiceNum(); // to know the amount
		for (int i = 0; i < 3; i++)
		{
			pGrid->AdvanceCurrentPlayer();                // to apply on the first palyer after the current one
			pPlayer=pGrid->GetCurrentPlayer();
		
			CellPosition pos=(pPlayer->GetCell())->GetCellPosition();
			pos.AddCellNum(-amount);
			pGrid->UpdatePlayerCell(pPlayer ,pos);

			Cell pCell(pos);
			if(pCell.HasCard()){
			Card *c=(Card*)pCell.GetGameObject();
			c->Apply(pGrid,pPlayer);
				}
			else if(pCell.HasLadder()){
			Ladder *l=(Ladder*)pCell.GetGameObject();
			l->Apply(pGrid,pPlayer);
			}
			else if(pCell.HasSnake()){
			Snake *s=(Snake*)pCell.GetGameObject();
			s->Apply(pGrid,pPlayer);
			}
			else if (pCell.HasCoinSet()){
			CoinSet*co =(CoinSet*)pCell.GetGameObject();
			co->Apply(pGrid,pPlayer);
			}
		}
			pGrid->AdvanceCurrentPlayer();                 // to get back to the current player 
			pPlayer=pGrid->GetCurrentPlayer();
	
}
void BackwardCard_3::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void BackwardCard_3::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum;

	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}
BackwardCard_3::~BackwardCard_3()
{
}
