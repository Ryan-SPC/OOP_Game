#include "GameObject.h"
namespace game_framework {
	class Block: public GameObject {
	public:
		Block();
		void LoadBitMap(int pic, int x, int y);
		void OnShow();
		void PlayerLeft();							// player向左移動時 物件執行相對位移
		void PlayerRight();							// player向右移動時 物件執行相對位移
		void PlayerUp();							// player向上移動時 物件執行相對位移
		void PlayerDown();							// player向下移動時 物件執行相對位移
		void Interact();							// 對話後可觸發項目
	private:
		CMovingBitmap blockPic;
		int X, Y;
	};
}