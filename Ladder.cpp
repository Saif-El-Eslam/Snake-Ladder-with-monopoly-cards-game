#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CoinSet.h"
#include <fstream>
#include <istream>


Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue");
	

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	//    Review the "pGrid" functions and decide which function can be used for that
	if(pPlayer->GetCell()->HasCard()){
		Card *c=(Card*)pPlayer->GetCell()->GetGameObject();
		c->Apply(pGrid,pPlayer);
	}
	else if(pPlayer->GetCell()->HasCoinSet()){
		CoinSet *Co=(CoinSet*)pPlayer->GetCell()->GetGameObject();
		Co->Apply(pGrid,pPlayer);
	} 
	if (CellPosition::GetCellNumFromPosition(endCellPos)==99)
		pGrid->SetEndGame(1);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}


void Ladder::Save(ofstream &OutFile, int type)
{
	if (type == 0)
		OutFile << position.GetCellNum() << "   " << endCellPos.GetCellNum() << endl;
}

void Ladder::OpenSaved(ifstream &Infile)
{
	int nums, nume;
	CellPosition *pos;

	Infile >> nums >> nume;

	pos->GetCellPositionFromNum(nums);
	pos->GetCellPositionFromNum(nume);

}


Ladder::~Ladder()
{
}
