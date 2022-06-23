#include "Card.h"
#include <fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}
void Card::setPosition(CellPosition p)
{
	position=p;
}
void Card::Draw(Output* pOut) const
{
	pOut->DrawCell(position,cardNumber);

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// The following line is to print the following message if a player reaches a card of any type

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}


void Card::Save(ofstream& OutFile, int type)
{	
}

void Card::OpenSaved(ifstream &Infile)
{
}



Card::~Card()
{
}
