#ifndef MAP_ARRAY_H
#define MAP_ARRAY_H
#include "MapObject.h"

namespace game_framework{
	class MapArray : public vector<vector<MapObject*>>{
	public:	
		MapArray();
		~MapArray();
		void LoadBitMap();
		void Build(int, int);					// �ظm�x�}
		int GetBPoint(int, int);				// �^�Ǫ��׫Y��
		bool IsBlock(int, int);					// �^�ǬO�_�Q����
		void SetBPoint(int, int, int);			// �]�w���׫Y��
		void OnShow();
		void PlayerDown();						// Down all MapObject
		void PlayerLeft();						// Left all MapObject
		void PlayerUp();						// Right all MapObject
		void PlayerRight();						// Up all MapObject

	private:
		int _row, _col;
		vector<vector<int>> _bPoint_vector;		// �s����׫Y�ƪ��G���x�}
  };
}
#endif // !MAP_ARRAY_H
