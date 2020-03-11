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

	int MapArray::GetInt(int row, int col) {
		return _int_vector[row][col];
	}

	void MapArray::SetInt(int s,int row, int col) {
		_int_vector[row][col] = s;
	}

	void MapArray::SetSize(int row, int col) {
		_row = row;
		_col = col;
		vector<int> unitRow;
		unitRow.assign(col, 0);
		_int_vector.assign(row, unitRow);
	}

	void MapArray::OnShow() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				this->at(i).at(j).OnShow();
			}
		}
	}

	
}
