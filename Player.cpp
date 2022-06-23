#include "Player.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CoinSet.h"
#include "PreventCard_4.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->prevent=false;
	preventtimes=0;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

void Player::SetturnCount(int turncount)
{
	turnCount = turncount;
}

void Player::setprevent(bool p)
{
	prevent= p;
}
bool Player::getprevent()
{
	return prevent; 
}void Player::setpreventtimes(int t)
{
	preventtimes=t;
}
int Player::getpreventtimes()
{
	return preventtimes;
}
void Player::setBenefit(int b)
{
	Benefit=b;
}
int Player::getBenefit()
{
	return Benefit;
}


// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	if (turnCount == 3)
	{
		turnCount = 0;
		wallet += (diceNumber * 10);
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		return;
	}
	if (this->GetWallet()<0)
	{
		pGrid->PrintErrorMessage("you don't have enough money wait for a few turns to gain some!");
		return;
	}
		// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"

	CellPosition pos=pCell->GetCellPosition();
	int cellnum= pos.GetCellNumFromPosition(pos);
	if (cellnum+justRolledDiceNum >99)
	{
		int N;
		N = 99 - cellnum;
		string strN;
		strN = to_string(N);
		pGrid->PrintErrorMessage("your dice value must equals to" + strN);
	
		return;
	}
	
	cellnum+=justRolledDiceNum;
	pos=pos.GetCellPositionFromNum(cellnum);
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
		// 6- Apply() the game object of the reached cell (if any)
	if (justRolledDiceNum != 0)
	{
		if (this->pCell->HasCard())          
		{
			Card* c;
			c = (Card*)this->pCell->GetGameObject();
			c -> Apply(pGrid, this);
		}
		if (this->pCell->HasCoinSet())          
		{
			CoinSet* co;
			co = (CoinSet*)this->pCell->GetGameObject();
			co -> Apply(pGrid, this);
		}
		else if (this->pCell->HasSnake())
		{
			Snake* s;
			s = (Snake*)this->pCell->GetGameObject();
			s -> Apply(pGrid, this);
		}
		else if (this->pCell->HasLadder())
		{
			Ladder* l;
			l = (Ladder*)this->pCell->GetGameObject();
			l -> Apply(pGrid, this);
		}
	}

		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pos.GetCellNumFromPosition(pos)==99)
		pGrid->SetEndGame(true);

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}