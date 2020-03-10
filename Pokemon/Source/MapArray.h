#include "block.h"
namespace game_framework{
	class MapArray : public vector<vector<MapObject>>{
	public:
		MapArray();
		void SetSize(int, int);

	private:
		int _row;
		int _col;
		vector<vector<int>> _int_vector;
		vector <vector<MapObject*>> _obj_vector;
  };
}
