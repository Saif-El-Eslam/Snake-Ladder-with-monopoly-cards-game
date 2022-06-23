#pragma once
#include "Action.h"

class AddCoinSetAction : public Action
{
	CellPosition coinsetPosition; // Cell position of the coin set 
	int coinsetAmount;   // the value that a coin set has
public:
	AddCoinSetAction( ApplicationManager *pApp); // constructor

	virtual void ReadActionParameters(); // Reads AddCoinSetAction parameters (coinsetAmount, coisnetPosition)

	virtual void Execute(); // Creates a new coinset Object of the specific Coinset value
							// and Reads the Parameters of This Coin set (if any)
							// then Sets this Coinset Object to GameObject Pointer of its Cell

	virtual ~AddCoinSetAction(); // A Virtual Destructor



};