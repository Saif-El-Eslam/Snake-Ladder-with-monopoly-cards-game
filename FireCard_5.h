#pragma once
#include "card.h"
class FireCard_5 :
	public Card
{
public:
	FireCard_5(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);
	~FireCard_5(void);
};

