#pragma once
#include "card.h"
class BackwardCard_3 :
	public Card
{
public:
	BackwardCard_3(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);
	~BackwardCard_3();
};

