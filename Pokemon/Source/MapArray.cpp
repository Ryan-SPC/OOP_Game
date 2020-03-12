#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "MapArray.h"
namespace game_framework{
	///
	void MapArray::LoadBitMap() {
		for (int i = 0; i < _row; i++) {
			int m = this->at(i).size();
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					this->at(i).at(j)->LoadBitMap();
			}
		}
	}
	///
	MapArray::MapArray() {
		_row = 0;
		_col = 0;
	}

	MapArray::~MapArray() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					delete this->at(i).at(j);
			}
		}
	}

	int MapArray::GetBPoint(int row, int col) {
		return _bPoint_vector[row][col];
	}

	void MapArray::SetBPoint(int s,int row, int col) {
		_bPoint_vector[row][col] = s;
	}

	bool MapArray::IsBlock(int row, int col) {
		return _bPoint_vector[row][col] == 1;
	}

	void MapArray::Build(int row, int col) {
		_row = row;
		_col = col;
		vector<int> unitIntRow;
		unitIntRow.assign(col, 0);
		_bPoint_vector.assign(row, unitIntRow);
		vector<MapObject*> unitObjRow;
		unitObjRow.assign(col, nullptr);
		this->assign(row, unitObjRow);
	}

	void MapArray::OnShow() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					this->at(i).at(j)->OnShow();
			}
		}
	}

	void MapArray::PlayerDown() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					this->at(i).at(j)->PlayerDown();
			}
		}
	}

	void MapArray::PlayerLeft() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					this->at(i).at(j)->PlayerLeft();
			}
		}
	}

	void MapArray::PlayerUp() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					this->at(i).at(j)->PlayerUp();
			}
		}
	}

	void MapArray::PlayerRight() {
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (this->at(i).at(j) != nullptr)
					this->at(i).at(j)->PlayerRight();
			}
		}
	}
	
}
