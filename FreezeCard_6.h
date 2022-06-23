#pragma once
#include "card.h"
class FreezeCard_6 :
	public Card
{
	bool  EvenOrOdd;
	int NumberOfTurns;
public:
	FreezeCard_6(const CellPosition & pos);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, int type);
	void OpenSaved(ifstream &Infile);
	void SetEvenOrOdd(bool);
	void SetNumberOfTurns(int);
	~FreezeCard_6(void);
};

