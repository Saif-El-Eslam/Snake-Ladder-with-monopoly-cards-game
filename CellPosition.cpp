#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v <= 8 && v>=0)
	{
		vCell = v;
		return true;
	}
	else
	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h <= 10 && h >= 0)
	{
		hCell = h;
		return true;
	}
	else
	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if (vCell >= 0 && vCell < 8 && hCell >= 0 && vCell <= 10)
		return true;
	else	
	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int VC = cellPosition.VCell();
	int HC = cellPosition.HCell();
	int cellNum = -1;

	if (VC != -1 && HC != -1)
	{
		cellNum = 0;
		if (HC > VC)
			--VC;

		
		cellNum += 10 * (8 - VC);
		
		if (HC > VC)
		{
			VC++;
			cellNum += HC - (VC + 1);
		}
		else
			cellNum += HC + 1 + (8 - VC);

	}

	return cellNum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	CellPosition position;
	int a, b;
	a=cellNum%10;
	b=(cellNum%100)/10;
	if (a>b)
	{
		position.SetVCell(NumVerticalCells-1-b);
		position.SetHCell(a-b-1);
	}
	else if(a<b)
	{
		position.SetVCell(NumVerticalCells-b);
		position.SetHCell(NumHorizontalCells-1-(b-a));
	}
	else if(a==b)
	{
		position.SetVCell(NumVerticalCells-b);
		position.SetHCell(NumHorizontalCells-1);
	}

	/// TODO: Implement this function as described in the .h file
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	/// TODO: Implement this function as described in the .h file
	GetCellPositionFromNum(addedNum + GetCellNum());

	// Note: this function updates the data members (vCell and hCell) of the calling object

}