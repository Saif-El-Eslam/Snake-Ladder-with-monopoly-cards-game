#pragma once

#include "Card.h"

class MonopolyCard_7:	public Card
{
	int Price;
	int fees;
	int size;
	CellPosition* Array_Of_Cells;
	Player* pOwner;
	Player* pTenant;
	bool Owned;
	bool Offered;
	bool IsMortgaged;
public:
	MonopolyCard_7(const CellPosition & pos); 
	virtual void ReadCardParameters(Grid * pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Collectingfees(Player* pPlayerpaying);
	int getPrice();
	int getFees;
	Player* getOwner();

	void setTenant(Player* pPlayer);
	Player* getTenant();
	void SetIsMortgaged(bool);
	bool GetIsMortgaged();

	void SetOffered(bool);
	bool GetOffered();

	void PassedArrayOfCells (CellPosition *&Cell_Position);
	void setOwner(Player* pPlayer);
	//virtual Card* copyparameters(CellPosition);
	void Save(ofstream&OutFile,int type);
	void OpenSaved(ifstream &Infile);

	void SetPrice(int x);
	void SetFees(int x);

	~MonopolyCard_7();
};

