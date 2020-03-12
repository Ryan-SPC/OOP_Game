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
		~Map();
		void LoadBitMap(int, int);					// 載入圖片(根据想初始想顯示位置給予int x, y)
		void OnShow();
		void OnMove();
		void SetPic(int, int, int);					// 設定圖片ID,圖片size (size請給正確)
		void SetPlayerDown(bool flag);				// 設定是否player正在往下移動
		void SetPlayerLeft(bool flag);				// 設定是否player正在往左移動
		void SetPlayerRight(bool flag);				// 設定是否player正在往右移動
		void SetPlayerUp(bool flag);				// 設定是否player正在往上移動
		void SetObject(MapObject* , int, int);      // 在地圖放入物件
	private:
		int _picID;									// 圖片ID
		int _height, _width;						// 圖片長寬
		CMovingBitmap mapPic;
		int X, Y;									// 圖片位置
		double pX, pY;								// player所在陣列位置
		MapArray MA;								// map用二維陣列
		int _row, _col;								// 二維陣列大小為 row * col
		bool isPlayerDown;							// 是否player正在往下移動
		bool isPlayerLeft;							// 是否player正在往左移動
		bool isPlayerRight;							// 是否player正在往右移動
		bool isPlayerUp;							// 是否player正在往上移動

		bool IsDownBlock();							// 使否無法向下移動
		bool IsLeftBlock();							// 使否無法向左移動
		bool IsRightBlock();						// 使否無法向右移動
		bool IsUpBlock();							// 使否無法向上移動
	};
}

#endif // !MAP_H


