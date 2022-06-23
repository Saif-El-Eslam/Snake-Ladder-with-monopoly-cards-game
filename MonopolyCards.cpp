#include "MonopolyCards.h"


MonopolyCards::MonopolyCards(const CellPosition & pos)
	:Card(pos)
{
	arraysize=0;
	pOwner=NULL;
}

void MonopolyCards::setprice(int set)
{
	price=set;
}
void MonopolyCards::setfees(int set)
{
	fees=set;
}
void MonopolyCards::setOwner(Player* pPlayer)
{
	pOwner=pPlayer;
}
void MonopolyCards::ReadCardParameters(Grid * pGrid)
{

}
void MonopolyCards::Apply(Grid* pGrid, Player* pPlayer)
{

}
void MonopolyCards::CollectingRent(Player* pPlayerpaying)
{

}
void MonopolyCards::PassedArrayOfCells (CellPosition *&Cell_Position)
{

}
void MonopolyCards::EditParameters(Grid*pGrid)
{

}
MonopolyCards::~MonopolyCards()
{
}
