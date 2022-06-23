#pragma once

#include "Action.h"

class DeleteGameObjectAction : public Action
{


	CellPosition DeletedPos;

public:
	DeleteGameObjectAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~DeleteGameObjectAction();

};