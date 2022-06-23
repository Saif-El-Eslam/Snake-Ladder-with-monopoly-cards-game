#pragma once
#include "card.h"
class LoseCityCard_13 :
	public Card
{
public:
	LoseCityCard_13(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);
	~LoseCityCard_13(void);
};

