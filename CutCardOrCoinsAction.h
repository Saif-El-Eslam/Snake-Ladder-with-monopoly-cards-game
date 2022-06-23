#pragma once

#include "Action.h"

class CutCardOrCoinsAction : public Action
{


	CellPosition CuttedPos;

public:
	CutCardOrCoinsAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~CutCardOrCoinsAction();

};