#pragma once
#include "card.h"
class MonopolyCards :
	public Card
{
	int fees;
	int price;
	int arraysize;
	CellPosition* OccupiedCells;
	Player* pOwner;
	bool Added;

public:
	MonopolyCards(const CellPosition & pos);
	void setprice(int set);
	void setfees(int set);
	void setOwner(Player* pPlayer);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void CollectingRent(Player* pPlayerpaying);
	void PassedArrayOfCells (CellPosition *&Cell_Position);
	void EditParameters(Grid*pGrid);
	~MonopolyCards(void);
};

	
