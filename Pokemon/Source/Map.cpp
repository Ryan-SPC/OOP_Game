#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "Map.h"

namespace game_framework {
	Map::Map() {
		isPlayerDown = isPlayerLeft = isPlayerRight = isPlayerUp = false;;
		_picID = _width = _height = _row = _col = 0;
	}

	Map::~Map() {
		// 會自動call MapArray解構元
	}

	void Map::SetPic(int picID, int height, int width) {
		_picID = picID;
		_height = height;
		_width = width;
		/// 有了地圖size才能建構矩陣 ///
		_row = _height / PIX;			
		_col = _width / PIX;			
		MA.Build(_row, _col);					// 建構矩陣
	}

	void Map::LoadBitMap(int x, int y) {
		mapPic.LoadBitmap(_picID);				// 載入圖檔
		X = x;
		Y = y;
		////初始定義玩家位置///
		pX = (320 - X) / PIX;
		pY = (200 - Y) / PIX;
		
		MA.LoadBitMap();
	}
	
	bool Map::IsUpBlock() {
		// pY, pX 可能為非整數 故取其Ceiling(Floor) *向上,左取Ceiling *向下,右取Floor
		int pRow = (int)ceil(pY);
		int pCol = (int)ceil(pX);
		if (pRow == 0)								// 到達邊界則直接回傳true
			return true;
		else
			return MA.IsBlock(pRow - 1, pCol);
	}

	bool Map::IsDownBlock() {
		// pY, pX 可能為非整數 故取其Ceiling(Floor) *向上,左取Ceiling *向下,右取Floor
		int pRow = (int)floor(pY);
		int pCol = (int)floor(pX);
		if (pRow == _row - 1)						// 到達邊界則直接回傳true
			return true;
		else
			return MA.IsBlock(pRow + 1, pCol);
	}

	bool Map::IsLeftBlock() {
		// pY, pX 可能為非整數 故取其Ceiling(Floor) *向上,左取Ceiling *向下,右取Floor
		int pRow = (int)ceil(pY);
		int pCol = (int)ceil(pX);
		if (pCol == 0)								// 到達邊界則直接回傳true
			return true;
		else
			return MA.IsBlock(pRow, pCol - 1);
	}

	bool Map::IsRightBlock() {
		// pY, pX 可能為非整數 故取其Ceiling(Floor) *向上,左取Ceiling *向下,右取Floor
		int pRow = (int)floor(pY);
		int pCol = (int)floor(pX);
		if (pCol == _col - 1)						// 到達邊界則直接回傳true
			return true;
		else
			return MA.IsBlock(pRow, pCol + 1);
	}


	void Map::SetObject(MapObject* obj, int row, int col) {
		obj->SetPosition(row, col);
		MA[row][col] = obj;
		MA.SetBPoint(1, row, col);
	}

	void Map::OnShow() {
		mapPic.SetTopLeft(X, Y);
		mapPic.ShowBitmap();		
		MA.OnShow();						// Show all MapObject
	}

	void Map::SetPlayerDown(bool flag) {
		isPlayerDown = flag;
		// 如果未移動完一格(PIX px) 則會繼續移動 (STEP/PIX px)
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
		// 如果未移動完一格(PIX px) 則會繼續移動 (STEP/PIX px)
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
		// 如果未移動完一格(PIX px) 則會繼續移動 (STEP/PIX px)
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
		// 如果未移動完一格(PIX px) 則會繼續移動 (STEP/PIX px)
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
