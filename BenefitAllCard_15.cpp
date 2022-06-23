#include "BenefitAllCard_15.h"
#include "fstream"

BenefitAllCard_15::BenefitAllCard_15(const CellPosition &pos) :Card(pos)
{
	cardNumber=15;
}


void BenefitAllCard_15::ReadCardParameters(Grid * pGrid)
{
	Input* input=pGrid->GetInput(); 
	Output* output=pGrid->GetOutput();
	pGrid->PrintErrorMessage("New BenfitAllCard : Enter the number of turns that a player would get benefit of all cities..");
	n_turns = input->GetInteger(output);
	while (n_turns<=0)
	{
		pGrid->PrintErrorMessage("Invalid! Please enter a valid number of turns..");
		n_turns=input->GetInteger(output);
	}
	output->ClearStatusBar();
}
void BenefitAllCard_15::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer=pGrid->GetCurrentPlayer();
	pPlayer->setBenefit(n_turns);
	for (int i=0; i<3 ; i++)
	{
	pGrid->AdvanceCurrentPlayer();
	pPlayer=pGrid->GetCurrentPlayer();
	pPlayer->setBenefit(0);
	}
	pGrid->AdvanceCurrentPlayer();
	pPlayer=pGrid->GetCurrentPlayer();
}
void BenefitAllCard_15::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum, n;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum >> n;

	n_turns = n;
	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}
void BenefitAllCard_15::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << n_turns << endl;
	}
}

void BenefitAllCard_15::Setn_turns(int x)
{
	n_turns = x;
}

BenefitAllCard_15::~BenefitAllCard_15(void)
{
}
