#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "CoinSet.h"
#include "Card.h"
#include "Player.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	ClipboardCard = NULL;
	ClipboardCoinSet = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}

// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboardCard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	ClipboardCard = pCard;
}

Card * Grid::GetClipboardCard() const // to be used in paste
{
	return ClipboardCard;
}

void Grid::SetClipboardCoinSet(CoinSet * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	ClipboardCoinSet = pCard;
}

CoinSet * Grid::GetClipboardCoinSet() const // to be used in copy/cut
{
	return ClipboardCoinSet;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

void Grid::SetcurrPlayerNumber(int Pnum)
{
	currPlayerNumber = Pnum;
}

int Grid::GetcurrPlayerNumber()
{
	return currPlayerNumber;
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder())
				return CellList[i][j]->HasLadder();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}

	startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i <= NumVerticalCells; i++) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j > 0; j--) // searching from startH and Right
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder())
				return CellList[i][j]->HasLadder();
		}
		startH = 10; // because in the next above rows, we will search from the first Right cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake * Grid::GetNextSnake(const CellPosition & position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake())
				return CellList[i][j]->HasSnake();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}

	startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i <= NumVerticalCells; i++) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j > 0; j--) // searching from startH and Right
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake())
				return CellList[i][j]->HasSnake();
		}
		startH = 10; // because in the next above rows, we will search from the first Right cell (hCell = 0) to the right
	}

	return NULL; // not found
}

Card * Grid:: GetNextCard(const CellPosition & position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasCard())
				return CellList[i][j]->HasCard();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}

	startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i <= NumVerticalCells; i++) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j > 0; j--) // searching from startH and Right
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasCard())
				return CellList[i][j]->HasCard();
		}
		startH = 10; // because in the next above rows, we will search from the first Right cell (hCell = 0) to the right
	}

	return NULL; // not found
}

CoinSet * Grid::GetNextCoinSet(const CellPosition & position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasCoinSet())
				return CellList[i][j]->HasCoinSet();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}

	startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i <= NumVerticalCells; i++) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j > 0; j--) // searching from startH and Right
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasCoinSet())
				return CellList[i][j]->HasCoinSet();
		}
		startH = 10; // because in the next above rows, we will search from the first Right cell (hCell = 0) to the right
	}

	return NULL; // not found
}
// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		///TODO: Add the code that draws the CoinSet game objects
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCoinSet(pOut);
			}
		}



		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

Card* Grid::CopyCard(CellPosition&pos)
{
	Card* pCard = CellList[pos.VCell()][pos.HCell()]->HasCard();
	if (pCard)
	{
		return pCard;
	}
}

CoinSet* Grid::CopyCoinSet(CellPosition&pos)
{
	CoinSet* pCoinSet = CellList[pos.VCell()][pos.HCell()]->HasCoinSet();
	if (pCoinSet)
	{
		return pCoinSet;
	}
}

Card* Grid :: GetCardPointer(CellPosition position, int Card_Number)                                          
{
	int Cellnum = position.GetCellNum();
	Card* pCard = this->CellList[position.VCell()][position.HCell()]->HasCard();
	if (pCard != NULL)
	{
		int Clicked_Card_Number= pCard->GetCardNumber();

		int Cell_Number_Of_Card = (pCard->GetPosition()).GetCellNum();   
		if (Cellnum == Cell_Number_Of_Card  && Clicked_Card_Number== Card_Number)
		{
			return pCard;
		}
	}
	return 0;
}

bool Grid::IsThereACard(const CellPosition position, int &Clicked_Card_Number)
{
	int Cell_Number_Of_Position = position.GetCellNum();
	Card* pcard = this->CellList[position.VCell()][position.HCell()]->HasCard();
	if (pcard != NULL)
	{
		int Cell_Number_Of_Card = (pcard->GetPosition()).GetCellNum();
		if (Cell_Number_Of_Position  == Cell_Number_Of_Card)
		{
			Clicked_Card_Number = pcard->GetCardNumber();
			return true;
		}
	}
	return false;
}

void Grid::SaveAll(ofstream & OutFile, int t)
{
	for (int i = (NumVerticalCells-1) ; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->GetGameObject())
				CellList[i][j]->GetGameObject()->Save(OutFile, t);
		}
	}


}

int Grid::GetLaddersNum()
{
	int LaddersNum = 0;
	for (int i = NumVerticalCells-1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
				LaddersNum++;
		}
	}

	return LaddersNum;
}
int Grid::GetSnakesNum()
{
	int SnakesNum = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
				SnakesNum++;
		}
	}

	return SnakesNum;
}

int Grid::GetCoinSetsNum()
{
	int CoinSetsNum = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
				CoinSetsNum++;
		}
	}

	return CoinSetsNum;
}

int Grid::GetCardsNum()
{
	int CardsNum = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
				CardsNum++;
		}
	}

	return CardsNum;
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}