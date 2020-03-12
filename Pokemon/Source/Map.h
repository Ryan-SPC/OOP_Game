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
		void LoadBitMap(int, int, int);
		void OnShow();
		void OnMove();
		void SetPlayerDown(bool flag);				// �]�w�O�_player���b���U����
		void SetPlayerLeft(bool flag);				// �]�w�O�_player���b��������
		void SetPlayerRight(bool flag);				// �]�w�O�_player���b���k����
		void SetPlayerUp(bool flag);				// �]�w�O�_player���b���W����
		void SetObject(MapObject* , int, int);      // �b�a�ϩ�J����
	private:
		CMovingBitmap mapPic;
		int X, Y;
		double pX, pY;								// player�Ҧb�}�C��m
		MapArray MA;								//map�ΤG���}�C
		int row, col;								// �G���}�C�j�p�� row * col
		bool isPlayerDown;							// �O�_player���b���U����
		bool isPlayerLeft;							// �O�_player���b��������
		bool isPlayerRight;							// �O�_player���b���k����
		bool isPlayerUp;							// �O�_player���b���W����

		void SetMapVector();						//�]�w�G���}�C
		bool IsDownBlock();							//�ϧ_�L�k�V�U����
		bool IsLeftBlock();							//�ϧ_�L�k�V������
		bool IsRightBlock();						//�ϧ_�L�k�V�k����
		bool IsUpBlock();							//�ϧ_�L�k�V�W����
	};
}

#endif // !MAP_H


