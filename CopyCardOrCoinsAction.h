#pragma once

#include "Action.h"

class CopyCardOrCoinsAction : public Action
{

	
	CellPosition CopiedPos;

public:
	CopyCardOrCoinsAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~CopyCardOrCoinsAction();

};