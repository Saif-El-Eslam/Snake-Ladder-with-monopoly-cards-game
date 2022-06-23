#pragma once
#include "Action.h"



class OfferMortgageAction : public Action
{
	int* Cities;
	int Size;

public:
	OfferMortgageAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~OfferMortgageAction();
};