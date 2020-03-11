#include "block.h"
namespace game_framework{
	class MapArray : public vector<vector<MapObject>>{
	public:
		MapArray();
		void SetSize(int, int);
		int GetInt(int, int);
		void SetInt(int, int, int);
		void OnShow();

	private:
		int _row;
		int _col;
		double pr, pc;
		vector<vector<int>> _int_vector;
  };
}
