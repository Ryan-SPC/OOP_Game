#ifndef MAP_H
#define MAP_H

#include"MapArray.h"
constexpr int PIX = 40;								//地圖一格大小為 PIX * PIX
constexpr int STEP = 10;							//移動時每幀移動格數
namespace game_framework {
	class Map
	{
	public:
		Map();
		void LoadBitMap(int, int, int);
		void OnShow();
		void OnMove();
		void SetPlayerDown(bool flag);				// 設定是否player正在往下移動
		void SetPlayerLeft(bool flag);				// 設定是否player正在往左移動
		void SetPlayerRight(bool flag);				// 設定是否player正在往右移動
		void SetPlayerUp(bool flag);				// 設定是否player正在往上移動
		void SetObject(MapObject* , int, int);              // 在地圖放入物件
	private:
		CMovingBitmap mapPic;
		int X, Y;
		double pX, pY;								// player所在陣列位置
		MapArray MA;
		
		//Block block;								// 測試用
		int row, col;								// 二維陣列大小為 row * col
		bool isPlayerDown;							// 是否player正在往下移動
		bool isPlayerLeft;							// 是否player正在往左移動
		bool isPlayerRight;							// 是否player正在往右移動
		bool isPlayerUp;							// 是否player正在往上移動

		void SetMapVector();						//設定二維陣列
		bool IsDownBlock();
		bool IsLeftBlock();
		bool IsRightBlock();
		bool IsUpBlock();
	};
}

#endif // !MAP_H


