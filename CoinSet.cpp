#include "CoinSet.h"
#include <fstream>
#include <istream>


CoinSet::CoinSet(const CellPosition & pos)
	:GameObject(pos)
{
}
void CoinSet::SetAmount(int x)
{
	Amount = x;
}
int CoinSet::getAmount()
{
	return Amount;
}

void CoinSet::setPosition(CellPosition p)
{
	position=p;
}
void CoinSet::Draw(Output* pOut)const
{
	pOut->DrawCoinSet(position);
}

void CoinSet::inputAmount(Grid * pGrid)
{
	Input* input=pGrid->GetInput(); 
	Output* output=pGrid->GetOutput();
	pGrid->PrintErrorMessage("New CoinSet: Enter its Amount...");
	int amount =input->GetInteger(output);
	Amount=amount;
	output->ClearStatusBar();
}

void CoinSet::Apply(Grid* pGrid, Player* pPlayer)
{
	int currentwallet= pPlayer->GetWallet();
	pPlayer->SetWallet(currentwallet+Amount);
}


void CoinSet::Save(ofstream &OutFile, int type)
{
	if (type == 2)
		OutFile << position.GetCellNum() << "   " << Amount << endl;
}

void CoinSet::OpenSaved(ifstream &Infile)
{
	int num, amount;
	CellPosition *pos;

	Infile >> num >> amount;

	pos->GetCellPositionFromNum(num);
}


CoinSet::~CoinSet()
{

}