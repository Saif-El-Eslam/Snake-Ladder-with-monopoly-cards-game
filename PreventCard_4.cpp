#include "PreventCard_4.h"
#include "fstream"

PreventCard_4::PreventCard_4(const CellPosition & pos):Card(pos)
{
	cardNumber=4;
}

void PreventCard_4::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Input* input=pGrid->GetInput(); 
	Output* output=pGrid->GetOutput();
	pGrid->PrintErrorMessage("New Prevent Card: Please Click on the Player's cell that would be affected ");
	CellPosition cellpos=input->GetCellClicked();
	int cellnum = cellpos.GetCellNum();
	pPlayer=pGrid->GetCurrentPlayer();
 
		for (int i = 0; i < 3; i++)
		{
			pGrid->AdvanceCurrentPlayer();               
			pPlayer=pGrid->GetCurrentPlayer();
			int pcellnum=(pPlayer->GetCell())->GetCellPosition().GetCellNum();
			if (pcellnum==cellnum)
			{
				pPlayer->setprevent(true);
				pPlayer->setpreventtimes(1);
				/*This can be handled as getting a value of zero instead of a dice roll. This means that the
				cancelled turn counts normally towards recharge the wallet turn*/
			}
			
		}
			pGrid->AdvanceCurrentPlayer();                
			pPlayer=pGrid->GetCurrentPlayer();
	
}
void PreventCard_4::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void PreventCard_4::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum;

	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}
PreventCard_4::~PreventCard_4()
{
}
