#pragma once
#include "Action.h"



class PasteAction : public Action
{
	CellPosition CellPos;

public:
	PasteAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~PasteAction();
};