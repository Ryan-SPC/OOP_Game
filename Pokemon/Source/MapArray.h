#ifndef MAP_ARRAY_H
#define MAP_ARRAY_H
#include "MapObject.h"

namespace game_framework{
	class MapArray : public vector<vector<MapObject*>>{
	public:	
		MapArray();
		~MapArray();
		void LoadBitMap();
		void Build(int, int);					// 建置矩陣
		int GetBPoint(int, int);				// 回傳阻擋係數
		bool IsBlock(int, int);					// 回傳是否被阻擋
		void SetBPoint(int, int, int);			// 設定阻擋係數
		void OnShow();
		void PlayerDown();						// Down all MapObject
		void PlayerLeft();						// Left all MapObject
		void PlayerUp();						// Right all MapObject
		void PlayerRight();						// Up all MapObject

	private:
		int _row, _col;
		vector<vector<int>> _bPoint_vector;		// 存放阻擋係數的二為矩陣
  };
}
#endif // !MAP_ARRAY_H
