#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "Map.h"

namespace game_framework {
	Map::Map(){
		isPlayerDown = false;
		isPlayerLeft = false;
		isPlayerRight = false;
		isPlayerUp = false;
	}

	void Map::SetMapVector() {	
		////map�� row * col ���G���x�}////
		row = mapPic.Height() / PIX;			//row�P�ɬ�Y��t��
		col = mapPic.Width() / PIX;			//col�P�ɬ�X��t��
		////��l�Ưx�} ������0////
		vector<int> ini_row;
		ini_row.assign(col, 0);
		map.assign(row, ini_row);
		////��l�w�q���a��m///
		pRow = (320 - X) / PIX;
		pCol = (200 - Y) / PIX;
	}

	//////////////////testing//////////////////////////////
	void Map::SetObject(int pic, int row, int col) {
		int x = col * PIX;
		int y = row * PIX;
		block.LoadBitMap(pic, x, y);
		map[row][col] = 1;
		v.push_back(&block);
	}
	//////////////////testing//////////////////////////////

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

	void Map::SetPlayerDown(bool flag) {
		isPlayerDown = flag;
		if (!isPlayerDown) {
			while (Y % PIX != 0) {
				Y -= STEP;
				block.PlayerDown();
				pCol += (double)STEP / PIX;
			}
		}			
	}

	void Map::SetPlayerLeft(bool flag) {
		isPlayerLeft = flag;
		if (!isPlayerLeft) {
			while (X % PIX != 0) {
				X += STEP;
				block.PlayerLeft();
				pRow -= (double)STEP / PIX;
			}
		}
	}

	void Map::SetPlayerRight(bool flag) {
		isPlayerRight = flag;
		if (!isPlayerLeft) {
			while (X % PIX != 0) {
				X -= STEP;
				block.PlayerRight();
				pRow += (double)STEP / PIX;
			}
		}
	}

	void Map::SetPlayerUp(bool flag) {
		isPlayerUp = flag;
		if (!isPlayerUp) {
			while (Y % PIX != 0) {
				Y += STEP;
				block.PlayerUp();
				pCol -= (double)STEP / PIX;
			}
		}
	}

	void Map::OnMove(){
		if (isPlayerDown && pCol < row - 1) {
			Y -= STEP;
			pCol += (double)STEP/PIX;
			block.PlayerDown();
		}			
		if (isPlayerLeft && pRow > 0) {
			X += STEP;
			pRow -= (double)STEP / PIX;
			block.PlayerLeft();
		}			
		if (isPlayerRight && pRow < col - 1) {
			X -= STEP;
			pRow += (double)STEP / PIX;
			block.PlayerRight();
		}
		if (isPlayerUp && pCol > 0) {
			Y += STEP;
			pCol -= (double)STEP / PIX;
			block.PlayerUp();
		}			
	}
}
