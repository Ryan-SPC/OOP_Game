#include "block.h"
#define PIX 40									//�a�Ϥ@�欰 PIX * PIX
namespace game_framework {
	class Map
	{
	public:
		Map();
		void LoadBitMap(int, int, int);
		void OnShow();
		void OnMove();
		void SetMovingDown(bool flag);				// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);				// �]�w�O�_���b��������
		void SetMovingRight(bool flag);				// �]�w�O�_���b���k����
		void SetMovingUp(bool flag);				// �]�w�O�_���b���W����
		void SetObject(int, int, int);
	private:
		CMovingBitmap mapPic;
		int X, Y;
		double pX, pY;
		vector<vector<int>> map;
		Block block;
		int row, col;
		bool isMovingDown;							// �O�_���b���U����
		bool isMovingLeft;							// �O�_���b��������
		bool isMovingRight;							// �O�_���b���k����
		bool isMovingUp;							// �O�_���b���W����

		void SetMapVector();
	};
}


