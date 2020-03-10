#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "MapArray.h"
namespace game_framework{
	MapArray::MapArray() {
		_row = 0;
		_col = 0;
	}

	void MapArray::SetSize(int row, int col) {
		_row = row;
		_col = col;

		vector<int> unitRow;
		unitRow.assign(col, 0);
		_int_vector.assign(row, unitRow);
	}

	template <class mObj> mObj MapArray::GetObject(int row, int col) {
		return _obj_vector[row][col];
	}

	int MapArray::GetInt(int row, int col) {
		return _int_vector[row][col];
	}

	int MapArray::GetRows() {
		return _row;
	}

	int MapArray::GetCols() {
		return _col;
	}
	
	template <class mObj> void MapArray::Add(mObj o, int row, int col) {
		_obj_vector[row][col] = o;
		_int_vector[row][col] = 10;
	}
}
