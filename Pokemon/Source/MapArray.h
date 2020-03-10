#include "block.h"
namespace game_framework{
	class MapArray{
	public:
		MapArray();
		void SetSize(int, int);
		template <class mObj> mObj GetObject(int, int);
		int GetInt(int, int);
		int GetRows();
		int GetCols();
		template <class mObj> void Add(mObj, int, int);

	private:
		int _row;
		int _col;
		vector<vector<int>> _int_vector;
		vector <vector<MapObject*>> _obj_vector;
  };
}
