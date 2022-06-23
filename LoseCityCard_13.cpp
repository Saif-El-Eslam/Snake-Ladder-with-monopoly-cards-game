#include "LoseCityCard_13.h"
#include "MonopolyCard_7.h"
#include "MonopolyCard_8.h"
#include "MonopolyCard_9.h"
#include "MonopolyCard_10.h"
#include "MonopolyCard_11.h"
#include "fstream"

LoseCityCard_13::LoseCityCard_13(const CellPosition & pos) :Card(pos)
{
	cardNumber=13;
}
void LoseCityCard_13::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer=pGrid->GetCurrentPlayer();
	int p[5];
	int pconst[5];
	Player* player[5];
	MonopolyCard_7* Mono7=NULL;
	for (int i=2; i<100;i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard=(pGrid->GetCardPointer(Cell_Position,7));    
		if (pCard !=NULL)
			Mono7=dynamic_cast<MonopolyCard_7*>(pCard);
		break;
	}
	 p[0]=Mono7->getPrice();
	 pconst[0]=p[0];
	 player[0]=Mono7->getOwner();
	MonopolyCard_8* Mono8=NULL;
	for (int i=2; i<100;i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard=(pGrid->GetCardPointer(Cell_Position,8));    
		if (pCard !=NULL)
			Mono8=dynamic_cast<MonopolyCard_8*>(pCard);
		break;
	}
	 p[1]=Mono8->getPrice();
	 pconst[1]=p[1];
	 player[1]=Mono8->getOwner();
	MonopolyCard_9* Mono9=NULL;
	for (int i=2; i<100;i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard=(pGrid->GetCardPointer(Cell_Position,9));    
		if (pCard !=NULL)
			Mono9=dynamic_cast<MonopolyCard_9*>(pCard);
		break;
	}
	p[2]=Mono9->getPrice();
	pconst[2]=p[2];
	player[2]=Mono9->getOwner();
	MonopolyCard_10* Mono10=NULL;
	for (int i=2; i<100;i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard=(pGrid->GetCardPointer(Cell_Position,10));    
		if (pCard !=NULL)
			Mono10=dynamic_cast<MonopolyCard_10*>(pCard);
		break;
	}
	p[3]=Mono10->getPrice();
	pconst[3]=p[3];
	player[3] =Mono10->getOwner();
	MonopolyCard_11* Mono11=NULL;
	for (int i=2; i<100;i++)
	{
		CellPosition Cell_Position(i);
		Card* pCard=(pGrid->GetCardPointer(Cell_Position,11));    
		if (pCard !=NULL)
			Mono11=dynamic_cast<MonopolyCard_11*>(pCard);
		break;
	}
	p[4]=Mono11->getPrice();
	pconst[4]=p[4];
	player[4] =Mono11->getOwner();
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = (i + 1); j < 5; j++)
		{
			int temp;
			Player* tp;
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				tp=player[i];
				player[i]=player[j];
				player[j]=tp;
			}
		}
	}
	int find;
	for (int i = 0; i < 5; i++)
	{
		if (player[i]==pPlayer)
			find=p[i];
			break;
	}
	
	if (find==pconst[0])
	{
		if (Mono7->GetIsMortgaged()==true)
			Mono7->setOwner(Mono7->getTenant());
		else 
			Mono7->setOwner(NULL);
	}
	if (find==pconst[1])
	{
		if (Mono8->GetIsMortgaged()==true)
			Mono8->setOwner(Mono8->getTenant());
		else 
		Mono8->setOwner(NULL);
	}
	if (find==pconst[2])
	{
		if (Mono9->GetIsMortgaged()==true)
			Mono9->setOwner(Mono9->getTenant());
		else 
		Mono9->setOwner(NULL);
	}
	if (find==pconst[3])
	{
		if (Mono10->GetIsMortgaged()==true)
			Mono10->setOwner(Mono10->getTenant());
		else 
		Mono10->setOwner(NULL);
	}
	if (find==pconst[4])
	
		if (Mono11->GetIsMortgaged()==true)
			Mono11->setOwner(Mono11->getTenant());
		else 
		Mono11->setOwner(NULL);
}


				// ßÏÇ åäÍÊÇÌ äÔíá ÍÇÌÇÊ Ýí Çá player áæ ÇÊÓÎÏãäÇ ÇáØÑíÞÉ Çááì ÝæÞ 
	/*int p11=Mono11->getPrice();
	if ((pPlayer->getSize())!=0)
	{
	int s=pPlayer->getSize();
	int* cityprices= new int[s];
	for (int i=0; i<s;i++)
	{
		if (pPlayer->getOwnedCities[i]==7 && p7>p8 &&p7>p9 && p7>p10 && p7>p11)
			Mono7->setOwner(NULL);
		if (pPlayer->getOwnedCities[i]==8 && p8>p7 &&p8>p9 && p8>p10 && p8>p11)
			Mono7->setOwner(NULL);
		if (pPlayer->getOwnedCities[i]==9 && p9>p8 &&p9>p7 && p9>p10 && p9>p11)
			Mono7->setOwner(NULL);
		if (pPlayer->getOwnedCities[i]==7 && p7>p8 &&p7>p9 && p7>p10 && p7>p11)
			Mono7->setOwner(NULL);
		if (pPlayer->getOwnedCities[i]==7 && p7>p8 &&p7>p9 && p7>p10 && p7>p11)
			Mono7->setOwner(NULL);
	}*/

	
	
	
void LoseCityCard_13::Save(ofstream &OutFile, int type)
{
	if (type == 3)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void LoseCityCard_13::OpenSaved(ifstream &Infile)
{
	int Cardnum, Cellnum;
	CellPosition *pos;

	Infile >> Cardnum >> Cellnum;

	cardNumber = Cardnum;
	pos->GetCellPositionFromNum(Cellnum);

}

LoseCityCard_13::~LoseCityCard_13(void)
{
}
