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

	
}
