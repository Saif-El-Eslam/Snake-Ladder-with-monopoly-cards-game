#pragma once
#include "card.h"
class NextCard_2 :
	public Card
{
	int numIndicator;
public:
	NextCard_2(const CellPosition & pos);
	virtual void ReadCardParameters( Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);
	void SetnumIndicator(int x);
	~NextCard_2();
};

