#pragma once

#include "Action.h"
#include "Action.h"
#include "Player.h"
#include "Grid.h"
#include "Cell.h"

class NewGameAction : public Action
{

public:
	NewGameAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~NewGameAction();
};
