#pragma once
#include "card.h"
class PreventCard_4 :
	public Card
{
	
public:
	PreventCard_4(const CellPosition & pos);
	
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);
	~PreventCard_4();
};

