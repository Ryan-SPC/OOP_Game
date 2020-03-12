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

	Map::~Map() {
		
	}

	bool Map::IsUpBlock() {
		int pRow = (int)ceil(pY);
		int pCol = (int)ceil(pX);
		if (pRow == 0)
			return true;
		else
			return MA.GetInt(pRow - 1, pCol) == 1;
	}

	bool Map::IsDownBlock() {
		int pRow = (int)floor(pY);
		int pCol = (int)floor(pX);
		if (pRow == row - 1)
			return true;
		else
			return MA.GetInt(pRow + 1, pCol) == 1;
	}

	bool Map::IsLeftBlock() {
		int pRow = (int)ceil(pY);
		int pCol = (int)ceil(pX);
		if (pCol == 0)
			return true;
		else
			return MA.GetInt(pRow, pCol - 1) == 1;
	}

	bool Map::IsRightBlock() {
		int pRow = (int)floor(pY);
		int pCol = (int)floor(pX);
		if (pCol == col - 1)
			return true;
		else
			return MA.GetInt(pRow, pCol + 1) == 1;
	}

	void Map::SetMapVector() {	
		////map為 row * col 的二維矩陣////
		row = mapPic.Height() / PIX;			//row同時為Y邊緣值
		col = mapPic.Width() / PIX;			//col同時為X邊緣值
		////初始定義玩家位置///
		pX = (320 - X) / PIX;
		pY = (200 - Y) / PIX;
		MA.SetSize(row, col);
	}

	void Map::SetObject(MapObject* obj, int row, int col) {
		obj->SetPosition(row, col);
		MA[row][col] = obj;
		MA.SetInt(1, row, col);
	}

	void Map::LoadBitMap(int pic, int x, int y) {
		mapPic.LoadBitmap(pic);				// 載入圖檔
		X = x;
		Y = y;
		SetMapVector();
	}

	void Map::OnShow() {
		mapPic.SetTopLeft(X, Y);
		mapPic.ShowBitmap();		
		MA.OnShow();						// Show all MapObject
	}

	void Map::SetPlayerDown(bool flag) {
		isPlayerDown = flag;
		if (!isPlayerDown) {
			while (Y % PIX != 0) {
				Y -= STEP;				
				pY += (double)STEP / PIX;				
				MA.PlayerDown();			// down all MapObject
			}
		}			
	}

	void Map::SetPlayerLeft(bool flag) {
		isPlayerLeft = flag;
		if (!isPlayerLeft) {
			while (X % PIX != 0) {
				X += STEP;
				pX -= (double)STEP / PIX;				
				MA.PlayerLeft();			// left all MapObject
			}
		}
	}

	void Map::SetPlayerRight(bool flag) {
		isPlayerRight = flag;
		if (!isPlayerLeft) {
			while (X % PIX != 0) {
				X -= STEP;
				pX += (double)STEP / PIX;				
				MA.PlayerRight();			// right all MapObject
			}
		}
	}

	void Map::SetPlayerUp(bool flag) {
		isPlayerUp = flag;
		if (!isPlayerUp) {
			while (Y % PIX != 0) {
				Y += STEP;
				pY -= (double)STEP / PIX;				
				MA.PlayerUp();				// up all MapObject
			}
		}
	}

	void Map::OnMove(){
		if (isPlayerDown && !IsDownBlock()) {
			Y -= STEP;
			pY += (double)STEP/PIX;
			MA.PlayerDown();			// down all MapObject
		}			
		if (isPlayerLeft && !IsLeftBlock()) {
			X += STEP;
			pX -= (double)STEP / PIX;
			MA.PlayerLeft();			// left all MapObject
		}			
		if (isPlayerRight && !IsRightBlock()) {
			X -= STEP;
			pX += (double)STEP / PIX;
			MA.PlayerRight();			// right all MapObject
		}
		if (isPlayerUp && !IsUpBlock()) {
			Y += STEP;
			pY -= (double)STEP / PIX;
			MA.PlayerUp();				// up all MapObject
		}			
	}
}
