#include "block.h"
#define PIX 40									//地圖一格為 PIX * PIX
namespace game_framework {
	class Map
	{
	public:
		Map();
		void LoadBitMap(int, int, int);
		void OnShow();
		void OnMove();
		void SetMovingDown(bool flag);				// 設定是否正在往下移動
		void SetMovingLeft(bool flag);				// 設定是否正在往左移動
		void SetMovingRight(bool flag);				// 設定是否正在往右移動
		void SetMovingUp(bool flag);				// 設定是否正在往上移動
		void SetObject(int, int, int);
	private:
		CMovingBitmap mapPic;
		int X, Y;
		double pX, pY;
		vector<vector<int>> map;
		Block block;
		int row, col;
		bool isMovingDown;							// 是否正在往下移動
		bool isMovingLeft;							// 是否正在往左移動
		bool isMovingRight;							// 是否正在往右移動
		bool isMovingUp;							// 是否正在往上移動

		void SetMapVector();
	};
}


