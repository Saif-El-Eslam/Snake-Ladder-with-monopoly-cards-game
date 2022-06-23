#include "FreezeCard_6.h"
#include "fstream"

FreezeCard_6::FreezeCard_6(const CellPosition & pos):Card(pos)
{
	cardNumber=6;
}

void FreezeCard_6::ReadCardParameters(Grid* pGrid)
{
	Input* input=pGrid->GetInput(); 
	Output* output=pGrid->GetOutput();
	output->PrintMessage("New Freeze Card: Enter 0 for even cells or enter 1 for odd cells ");

	int o_e	=input->GetInteger(output);
	while (o_e!=0 && o_e!=1)
	{
	output->PrintMessage("Invalid: Renter a vaild number..");	
		o_e=input->GetInteger(output);
	}
	if (o_e ==0)
		EvenOrOdd=true;
	if (o_e ==1)
		EvenOrOdd=false;
	output->PrintMessage("Enter the number of turns to freeze...");
	int n_turns	=input->GetInteger(output);
	while (n_turns<0)
	{
	output->PrintMessage("Invalid: Renter a vaild number..");	
		n_turns=input->GetInteger(output);
	}
	NumberOfTurns=n_turns;
	output->ClearStatusBar();
}
void FreezeCard_6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
		pPlayer=pGrid->GetCurrentPlayer();
	if (EvenOrOdd==true)
	{
		for (int i = 0; i < 3; i++)
		{
			pGrid->AdvanceCurrentPlayer();                // to apply on the first palyer after the current one
			pPlayer=pGrid->GetCurrentPlayer();
		
			int cellnum=(pPlayer->GetCell())->GetCellPosition().GetCellNum();
			if (cellnum%2 ==0)
			{
				//prevent
				pPlayer->setprevent(true);
				pPlayer->setpreventtimes(NumberOfTurns);
			}
			
		}
			pGrid->AdvanceCurrentPlayer();                 // to get back to the current player 
			pPlayer=pGrid->GetCurrentPlayer();
	}
	else if (EvenOrOdd==false)
	{
			pGrid->AdvanceCurrentPlayer();                // to apply on the first palyer after the current one
			pPlayer=pGrid->GetCurrentPlayer();

		int cellnum=(pPlayer->GetCell())->GetCellPosition().GetCellNum();
			if (cellnum%2 !=0)
			{
				//prevent
				pPlayer->setprevent(true);
				pPlayer->setpreventtimes(NumberOfTurns);
			}
			
			pGrid->AdvanceCurrentPlayer();                 // to get back to the current player 
			pPlayer=pGrid->GetCurrentPlayer();
	}
}
void FreezeCard_6::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << EvenOrOdd << " " << NumberOfTurns << endl;
	}
}

void FreezeCard_6::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum, turns;
	bool EO;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum >> EO >> turns;

	EvenOrOdd = EO;
	NumberOfTurns = turns;
	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}

void FreezeCard_6::SetEvenOrOdd(bool x)
{
	EvenOrOdd = x;
}
void FreezeCard_6::SetNumberOfTurns(int x)
{
	NumberOfTurns = x;
}


FreezeCard_6::~FreezeCard_6(void)
{
}
