#pragma once
#include "Action.h"



class OpenGridAction : public Action
{

	string FileName;

public:
	OpenGridAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~OpenGridAction();
};