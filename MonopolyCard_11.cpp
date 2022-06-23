#include "MonopolyCard_11.h"
#include <fstream>

MonopolyCard_11::MonopolyCard_11(const CellPosition & pos) : Card(pos)	
{
	cardNumber = 11;		 
	size=0;				    
	pOwner=NULL;
	IsMortgaged = false;
	Offered = false;
}
int MonopolyCard_11::getPrice()
{
	return Price;
}
Player* MonopolyCard_11::getOwner()
{
	return pOwner;
}
void MonopolyCard_11::setTenant(Player* p)
{
	pTenant = p;
}
Player* MonopolyCard_11::getTenant()
{
	return pTenant;
}
void MonopolyCard_11::SetOffered(bool b)
{
	Offered = b;
}
bool MonopolyCard_11::GetOffered()
{
	return Offered;
}
void MonopolyCard_11::ReadCardParameters(Grid * pGrid)
{
	Input *pIn = pGrid-> GetInput();
	Output *pOut = pGrid-> GetOutput();
    Owned=false;
	int CellsMono11;
	for (int i=1; i<100;i++)
	{
		CellPosition Cell_Position(i);
		Card *pCard=pGrid->GetCardPointer(Cell_Position,11);     
		if (pCard!=NULL)
		{
			Owned=true;
			CellsMono11=i;
			break;
		}
	}
	if (Owned)
	{
		CellPosition position(CellsMono11);
		MonopolyCard_11 *pMono11=dynamic_cast<MonopolyCard_11*>(pGrid->GetCardPointer(position,11));
		Price=pMono11->Price;
		fees=pMono11->fees;
	}
	else
	{
		pOut->PrintMessage("Enter the city price: ");
		Price= pIn->GetInteger(pOut);
		while (Price<=0)
		{
			pGrid->PrintErrorMessage("Invalid Price! ");
			pOut->PrintMessage("Enter the city price: ");
			Price= pIn->GetInteger(pOut);
		}

		pOut->PrintMessage("Enter the city fees:  ");
		fees= pIn->GetInteger(pOut);
		while (fees<=0)
		{
			pGrid->PrintErrorMessage("Invalid fees!");
			pOut->PrintMessage("Enter the city fees: ");
			fees= pIn->GetInteger(pOut);
		}
	}
	pOut->ClearStatusBar();
}
void MonopolyCard_11::SetIsMortgaged(bool m)
{
	IsMortgaged=m;
}
bool MonopolyCard_11::GetIsMortgaged()
{
	return IsMortgaged;
}


void MonopolyCard_11::Apply(Grid* pGrid, Player* pPlayer)
{
	Player* toBenefit;
	pPlayer=pGrid->GetCurrentPlayer();
	for (int i=0 ; i<4 ;i++  )
	{
		if (pPlayer->getBenefit() >0)
		{
			toBenefit=pPlayer;
			break;
		}
	pGrid->AdvanceCurrentPlayer();
	pPlayer=pGrid->GetCurrentPlayer();
	}
	
	if (toBenefit != NULL)
	{
		Collectingfees( toBenefit);
		toBenefit->setBenefit((toBenefit->getBenefit())-1);
	}
	else 
	{
	if (pOwner==NULL)		
	{
		Card :: Apply(pGrid, pPlayer);
		Input *pIn = pGrid-> GetInput();
		Output *pOut = pGrid-> GetOutput();

		pOut->PrintMessage("Do You Want To Buy This Cell? (Y/N)    The Price:"+ to_string(Price));
		string answer= pIn->GetSrting(pOut);
		while (answer !="Y" &&  answer != "N"  && answer != "y" && answer != "n") 
		{
			pOut->PrintMessage("Invalid Answer! Do you want to buy this cell? Y/N ");
			string *ans=&answer;
			*ans= pIn->GetSrting(pOut);
			pOut->ClearStatusBar();
		}
		if ( answer=="N" || answer== "n")
		{
			pOut->ClearStatusBar();
			return ;
		}
		if ( answer=="Y" || answer== "y")
		{
			pOut->ClearStatusBar();
			int Player_Wallet= pPlayer->GetWallet();
			if(Player_Wallet>= Price)
			{
				Player_Wallet= Player_Wallet - Price;
				pPlayer->SetWallet(Player_Wallet);
				pOwner=pPlayer;
				int k=0;
				for (int i=1; i<100;i++)
				{
					CellPosition Cell_Position(i);
					int Clicked_Card_Number=0;
					bool ans= pGrid->IsThereACard(Cell_Position,Clicked_Card_Number);      

					if (ans==true && Clicked_Card_Number==11)
						size++;
				}
				if (size==0)
				{
					return;
				}
				else if (size!=0)
				{
					Array_Of_Cells= new CellPosition[size];

					for (int i=1; i<100;i++)
					{
						CellPosition Cell_Position(i);
						int Clicked_Card_Number=0;
						bool ans= pGrid-> IsThereACard(Cell_Position,Clicked_Card_Number);    

						if (ans==true && Clicked_Card_Number==11)
						{ Array_Of_Cells[k]=Cell_Position;
						k++;
						}
					}

				}
				

				for (int i=0; i<size; i++)
				{ Card* pCard;

				pCard= pGrid->GetCardPointer(Array_Of_Cells[i], 13);
				((MonopolyCard_11*)pCard)->setOwner(pOwner);
				((MonopolyCard_11*)pCard)->PassedArrayOfCells(Array_Of_Cells);
				}  
			}
					
		}
		else if (pPlayer->GetWallet()< Price)
		{
			pGrid->PrintErrorMessage("You Don't Have Enough Money To Buy This Cell!");
			return;
		}
	}
	if(pOwner!=NULL)
	{ Collectingfees( pPlayer);
	return;
	}
}
} 



void MonopolyCard_11 :: setOwner(Player* pPlayer)
{
	pOwner= pPlayer;
}

void MonopolyCard_11 :: PassedArrayOfCells (CellPosition* &Cell_Position)
{
	Array_Of_Cells= Cell_Position;
}
void MonopolyCard_11 :: Collectingfees(Player* pPlayer)
{
	if (pPlayer != pOwner)
	{
		int Player_Wallet= pPlayer->GetWallet();
		Player_Wallet= Player_Wallet - fees;
		pPlayer->SetWallet(Player_Wallet);		
		int Owner_Wallet= pOwner->GetWallet();
		Owner_Wallet= Owner_Wallet+fees;
		pOwner->SetWallet(Owner_Wallet);
	}
}
/*
Card* MonopolyCard_11::copyparameters(CellPosition pos)
{
	Card* cp = new MonopolyCard_11(pos);
	return cp;
}*/
void MonopolyCard_11::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << Price << fees << endl;
	}
}

void MonopolyCard_11::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum, Cardprice, Cardfees;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum >> Cardprice >> Cardfees;

	cardNumber = Cardnum;
	Price = Cardprice;
	fees = Cardfees;
	pos->GetCellPositionFromNum(Cellnum);

}

void MonopolyCard_11::SetPrice(int x)
{
	Price = x;
}
void MonopolyCard_11::SetFees(int x)
{
	fees = x;
}

MonopolyCard_11::~MonopolyCard_11(void)
{
}