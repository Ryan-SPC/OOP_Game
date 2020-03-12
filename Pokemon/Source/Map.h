#ifndef MAP_H
#define MAP_H

#include"MapArray.h"
constexpr int PIX = 40;								//�a�Ϥ@��j�p�� PIX * PIX
constexpr int STEP = 10;							//���ʮɨC�V���ʮ��
namespace game_framework {
	class Map
	{
	public:
		Map();
		~Map();
		void LoadBitMap(int, int);					// ���J�Ϥ�(���u�Q��l�Q��ܦ�m����int x, y)
		void OnShow();
		void OnMove();
		void SetPic(int, int, int);					// �]�w�Ϥ�ID,�Ϥ�size (size�е����T)
		void SetPlayerDown(bool flag);				// �]�w�O�_player���b���U����
		void SetPlayerLeft(bool flag);				// �]�w�O�_player���b��������
		void SetPlayerRight(bool flag);				// �]�w�O�_player���b���k����
		void SetPlayerUp(bool flag);				// �]�w�O�_player���b���W����
		void SetObject(MapObject* , int, int);      // �b�a�ϩ�J����
	private:
		int _picID;									// �Ϥ�ID
		int _height, _width;						// �Ϥ����e
		CMovingBitmap mapPic;
		int X, Y;									// �Ϥ���m
		double pX, pY;								// player�Ҧb�}�C��m
		MapArray MA;								// map�ΤG���}�C
		int _row, _col;								// �G���}�C�j�p�� row * col
		bool isPlayerDown;							// �O�_player���b���U����
		bool isPlayerLeft;							// �O�_player���b��������
		bool isPlayerRight;							// �O�_player���b���k����
		bool isPlayerUp;							// �O�_player���b���W����

		bool IsDownBlock();							// �ϧ_�L�k�V�U����
		bool IsLeftBlock();							// �ϧ_�L�k�V������
		bool IsRightBlock();						// �ϧ_�L�k�V�k����
		bool IsUpBlock();							// �ϧ_�L�k�V�W����
	};
}

#endif // !MAP_H


