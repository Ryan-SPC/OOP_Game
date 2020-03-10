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

	bool Map::IsUpBlock() {
		int pRow = (int)ceil(pX);
		int pCol = (int)ceil(pY);
		if (pCol == 0)
			return true;
		else
			return map[pRow][pCol - 1] == 1;
	}

	bool Map::IsDownBlock() {
		int pRow = (int)ceil(pX);
		int pCol = (int)ceil(pY);
		if (pCol == col - 1)
			return true;
		else
			return map[pRow][pCol + 1] == 1;
	}

	bool Map::IsLeftBlock() {
		int pRow = (int)ceil(pX);
		int pCol = (int)ceil(pY);
		if (pRow == 0)
			return true;
		else
			return map[pRow - 1][pCol] == 1;
	}

	bool Map::IsRightBlock() {
		int pRow = (int)ceil(pX);
		int pCol = (int)ceil(pY);
		if (pRow == row - 1)
			return true;
		else
			return map[pRow + 1][pCol] == 1;
	}

	void Map::SetMapVector() {	
		////map為 row * col 的二維矩陣////
		row = mapPic.Height() / PIX;			//row同時為Y邊緣值
		col = mapPic.Width() / PIX;			//col同時為X邊緣值
		////初始化矩陣 全部填0////
		vector<int> ini_row;
		ini_row.assign(col, 0);
		map.assign(row, ini_row);
		////初始定義玩家位置///
		pX = (320 - X) / PIX;
		pY = (200 - Y) / PIX;

		vector<MapObject*> irow;
		irow.assign(col, nullptr);
		v.assign(row, irow);
	}

	//////////////////testing//////////////////////////////
	void Map::SetObject(int pic, int row, int col) {
		int x = col * PIX;
		int y = row * PIX;
		block.LoadBitMap(pic, x, y);
		map[row][col] = 1;	
		v[row][col] = &block;
	}
	//////////////////testing//////////////////////////////

	void Map::LoadBitMap(int pic, int x, int y) {
		mapPic.LoadBitmap(pic);				//載入圖檔
		X = x;
		Y = y;
		SetMapVector();
		SetObject(IDB_BLOCK,0,0);			//測試Block
	}

	void Map::OnShow() {
		mapPic.SetTopLeft(X, Y);
		mapPic.ShowBitmap();

		/// Show all MapObject
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				if (v[i][j] != nullptr)
					v[i][j]->OnShow();
		}
	}

	void Map::SetPlayerDown(bool flag) {
		isPlayerDown = flag;
		if (!isPlayerDown) {
			while (Y % PIX != 0) {
				Y -= STEP;				
				pY += (double)STEP / PIX;

				/// down all MapObject
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++)
						if (v[i][j] != nullptr)
							v[i][j]->PlayerDown();
				}
			}
		}			
	}

	void Map::SetPlayerLeft(bool flag) {
		isPlayerLeft = flag;
		if (!isPlayerLeft) {
			while (X % PIX != 0) {
				X += STEP;
				pX -= (double)STEP / PIX;

				/// left all MapObject
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++)
						if (v[i][j] != nullptr)
							v[i][j]->PlayerLeft();
				}
			}
		}
	}

	void Map::SetPlayerRight(bool flag) {
		isPlayerRight = flag;
		if (!isPlayerLeft) {
			while (X % PIX != 0) {
				X -= STEP;
				pX += (double)STEP / PIX;

				/// right all MapObject
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++)
						if (v[i][j] != nullptr)
							v[i][j]->PlayerRight();
				}
			}
		}
	}

	void Map::SetPlayerUp(bool flag) {
		isPlayerUp = flag;
		if (!isPlayerUp) {
			while (Y % PIX != 0) {
				Y += STEP;
				pY -= (double)STEP / PIX;

				/// up all MapObject
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++)
						if (v[i][j] != nullptr)
							v[i][j]->PlayerUp();
				}
			}
		}
	}

	void Map::OnMove(){
		if (isPlayerDown && pY < row - 1 && !IsDownBlock()) {
			Y -= STEP;
			pY += (double)STEP/PIX;
			
			/// down all MapObject
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++)
					if (v[i][j] != nullptr)
						v[i][j]->PlayerDown();
			}
		}			
		if (isPlayerLeft && pX > 0 && !IsLeftBlock()) {
			X += STEP;
			pX -= (double)STEP / PIX;
			
			/// left all MapObject
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++)
					if (v[i][j] != nullptr)
						v[i][j]->PlayerLeft();
			}
		}			
		if (isPlayerRight && pX < col - 1 && !IsRightBlock()) {
			X -= STEP;
			pX += (double)STEP / PIX;
			
			/// right all MapObject
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++)
					if (v[i][j] != nullptr)
						v[i][j]->PlayerRight();
			}
		}
		if (isPlayerUp && pY > 0 && !IsUpBlock()) {
			Y += STEP;
			pY -= (double)STEP / PIX;
			
			/// up all MapObject
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++)
					if (v[i][j] != nullptr)
						v[i][j]->PlayerUp();
			}
		}			
	}
}
