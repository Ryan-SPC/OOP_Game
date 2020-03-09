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
		row = mapPic.Height() / PIX;			//row�P�ɬ�Y��t��
		col = mapPic.Width() / PIX;			//col�P�ɬ�X��t��
		////��l�Ưx�} ������0////
		vector<int> ini_row;
		ini_row.assign(col, 0);
		map.assign(row, ini_row);
		////��l�w�q���a��m///
		pX = (320 - X) / 40;
		pY = (200 - Y) / 40;
	}

	void Map::SetObject(int pic, int row, int col) {
		int x = col * PIX;
		int y = row * PIX;
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
		if (!isMovingDown) {
			while (Y % PIX != 0) {
				Y -= 10;
				pY += 0.25;
			}
		}			
	}

	void Map::SetMovingLeft(bool flag) {
		isMovingLeft = flag;
		if (!isMovingLeft) {
			while (X % PIX != 0) {
				X += 10;
				pX -= 0.25;
			}
		}
	}

	void Map::SetMovingRight(bool flag) {
		isMovingRight = flag;
		if (!isMovingLeft) {
			while (X % PIX != 0) {
				X -= 10;
				pX += 0.25;
			}
		}
	}

	void Map::SetMovingUp(bool flag) {
		isMovingUp = flag;
		if (!isMovingUp) {
			while (Y % PIX != 0) {
				Y += 10;
				pY -= 0.25;
			}
		}
	}

	void Map::OnMove(){
		if (isMovingDown && pY < row - 1) {
			Y -= 10;
			pY += 0.25;
			block.MoveDown();
		}			
		if (isMovingLeft && pX > 0) {
			X += 10;
			pX -= 0.25;
			block.MoveLeft();
		}			
		if (isMovingRight && pX < col - 1) {
			X -= 10;
			pX += 0.25;
			block.MoveRight();
		}
		if (isMovingUp && pY > 0) {
			Y += 10;
			pY -= 0.25;
			block.MoveUp();
		}
			
	}
}
