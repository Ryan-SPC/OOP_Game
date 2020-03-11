#ifndef MAP_ARRAY_H
#define MAP_ARRAY_H
#include "MapObject.h"

namespace game_framework{
	class MapArray : public vector<vector<MapObject*>>{
	public:
		MapArray();
		void SetSize(int, int);
		int GetInt(int, int);
		void SetInt(int, int, int);
		void OnShow();
		void PlayerDown();
		void PlayerLeft();
		void PlayerUp();
		void PlayerRight();

	private:
		int _row;
		int _col;
		double pr, pc;
		vector<vector<int>> _int_vector;
  };
}
#endif // !MAP_ARRAY_H
