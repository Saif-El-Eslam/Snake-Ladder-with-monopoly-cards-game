#pragma once

#include "Card.h"

class MonopolyCard_10 :	public Card
{
	int Price;
	int fees;
	int size;
	CellPosition* Array_Of_Cells;
	Player* pOwner;
	Player* pTenant;
	bool Offered;
	bool Owned;
	bool IsMortgaged;
public:
	MonopolyCard_10(const CellPosition & pos); 
	
	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer);
                            
	void Collectingfees(Player* pPlayerpaying);
	int getPrice();
	Player* getOwner();

	void setTenant(Player* pPlayer);
	Player* getTenant();
	void SetIsMortgaged(bool);
	bool GetIsMortgaged();
	void SetOffered(bool);
	bool GetOffered();


	//virtual Card* copyparameters(CellPosition);
	void PassedArrayOfCells (CellPosition *&Cell_Position);
	void setOwner(Player* pPlayer);
	void Save(ofstream&OutFile,int type);
	void OpenSaved(ifstream &Infile);
	//virtual void Save(ofstream&OutFile,int type);

	void SetPrice(int x);
	void SetFees(int x);
	
	virtual ~MonopolyCard_10();
};

