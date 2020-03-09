#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "Map.h"

namespace game_framework {
	Map::Map(){
		isMovingDown = false;
		isMovingLeft = false;
		isMovingRight = false;
		isMovingUp = false;
	}

	void Map::SetMapVector() {	
		////map�� row X col ���G���x�}////
		row = mapPic.Height() / 40;			//row�P�ɬ�Y��t��
		col = mapPic.Width() / 40;			//col�P�ɬ�X��t��
		////��l�Ưx�} ������0////
		vector<int> ini_row;
		ini_row.assign(col, 0);
		map.assign(row, ini_row);
		////��l�w�q���a��m///
		pX = (320 - X) / 40;
		pY = (200 - Y) / 40;
	}

	void Map::SetObject(int pic, int row, int col) {
		int x = col * 40;
		int y = row * 40;
		block.LoadBitMap(pic, x, y);
		map[row][col] = 1;
	}

	void Map::LoadBitMap(int pic, int x, int y) {
		mapPic.LoadBitmap(pic);				//���J����
		X = x;
		Y = y;
		SetMapVector();
		SetObject(IDB_BLOCK,0,0);
	}

	void Map::OnShow() {
		mapPic.SetTopLeft(X, Y);
		mapPic.ShowBitmap();
		block.OnShow();
	}

	void Map::SetMovingDown(bool flag) {
		isMovingDown = flag;
	}

	void Map::SetMovingLeft(bool flag) {
		isMovingLeft = flag;
	}

	void Map::SetMovingRight(bool flag) {
		isMovingRight = flag;
	}

	void Map::SetMovingUp(bool flag) {
		isMovingUp = flag;
	}

	void Map::OnMove(){

		if (isMovingDown && pY < row - 1) {
			Y -= 40;
			pY++;
			block.MoveDown();
		}			
		if (isMovingLeft && pX > 0) {
			X += 40;
			pX--;
			block.MoveLeft();
		}			
		if (isMovingRight && pX < col - 1) {
			X -= 40;
			pX++;
			block.MoveRight();
		}
		if (isMovingUp && pY > 0) {
			Y += 40;
			pY--;
			block.MoveUp();
		}
			
	}
}
