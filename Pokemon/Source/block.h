#include "GameObject.h"
namespace game_framework {
	class Block: public GameObject {
	public:
		Block();
		void LoadBitMap(int pic, int x, int y);
		void OnShow();
		void PlayerLeft();							// player�V�����ʮ� �������۹�첾
		void PlayerRight();							// player�V�k���ʮ� �������۹�첾
		void PlayerUp();							// player�V�W���ʮ� �������۹�첾
		void PlayerDown();							// player�V�U���ʮ� �������۹�첾
		void Interact();							// ��ܫ�iĲ�o����
	private:
		CMovingBitmap blockPic;
		int X, Y;
	};
}