#pragma once

#include "GameObject.h"
#include "Player.h"

class CoinSet :	public GameObject 
{
	int Amount;
public:
	CoinSet(const CellPosition & pos);
	void Draw(Output* pOut) const; 
	
	void SetAmount(int x);
	int getAmount();

	void setPosition(CellPosition); 

	void inputAmount(Grid * pGrid);
	void Apply(Grid* pGrid, Player* pPlayer); 
	 
	virtual void Save(ofstream &OutFile, int type);

	virtual void OpenSaved(ifstream &Infile);
	
	~CoinSet();
};