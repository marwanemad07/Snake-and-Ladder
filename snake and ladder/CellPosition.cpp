#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{

	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}

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
	if (vCell == 0 && hCell == 10)
		return false;
	if (vCell == 8 && hCell == 0)
		return false;
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10)
		return true;

	else return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	int CellNum = 0;
	switch (cellPosition.vCell)
	{
	case 0: CellNum = 89; break;
	case 1: CellNum = 78; break;
	case 2: CellNum = 67; break;
	case 3: CellNum = 56; break;
	case 4: CellNum = 45; break;
	case 5: CellNum = 34; break;
	case 6: CellNum = 23; break;
	case 7: CellNum = 12; break;
	case 8: CellNum = 1; break;
	}
	switch (cellPosition.hCell)
	{
	case 0: CellNum += 0; break;
	case 1: CellNum += 1; break;
	case 2: CellNum += 2; break;
	case 3: CellNum += 3; break;
	case 4: CellNum += 4; break;
	case 5: CellNum += 5; break;
	case 6: CellNum += 6; break;
	case 7: CellNum += 7; break;
	case 8: CellNum += 8; break;
	case 9: CellNum += 9; break;
	case 10: CellNum += 10; break;
	}
	return CellNum;
	///TODO: Implement this function as described in the .h file



	//return 0; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	int temp;
	/// TODO: Implement this function as described in the .h file
	if (cellNum >= 89)
	{
		temp = cellNum; position.SetVCell(0);
	}
	else if (cellNum >= 78)
	{
		temp = cellNum; position.SetVCell(1);
	}
	else if (cellNum >= 67)
	{
		temp = cellNum; position.SetVCell(2);
	}
	else if (cellNum >= 56)
	{
		temp = cellNum; position.SetVCell(3);
	}
	else if (cellNum >= 45)
	{
		temp = cellNum; position.SetVCell(4);
	}
	else if (cellNum >= 34)
	{
		temp = cellNum; position.SetVCell(5);
	}
	else if (cellNum >= 23)
	{
		temp = cellNum; position.SetVCell(6);
	}
	else if (cellNum >= 12)
	{
		temp = cellNum; position.SetVCell(7);
	}
	else if (cellNum >= 1)
	{
		temp = cellNum; position.SetVCell(8);
	}
	switch (position.vCell)
	{
	case 0: position.SetHCell(temp - 89); break;
	case 1: position.SetHCell(temp - 78); break;
	case 2: position.SetHCell(temp - 67); break;
	case 3: position.SetHCell(temp - 56); break;
	case 4: position.SetHCell(temp - 45); break;
	case 5: position.SetHCell(temp - 34); break;
	case 6: position.SetHCell(temp - 23); break;
	case 7: position.SetHCell(temp - 12); break;
	case 8: position.SetHCell(temp - 1); break;
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int CellNum = GetCellNum() + addedNum;
	CellPosition x;
	x = GetCellPositionFromNum(CellNum);
	vCell = x.vCell;
	hCell = x.hCell;

	// Note: this function updates the data members (vCell and hCell) of the calling object

}