#include "GameObject.h"
namespace game_framework {
	class Block: public GameObject {
	public:
		Block();
		void LoadBitMap(int pic, int x, int y);
		void OnShow();
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		void Interact();
	private:
		CMovingBitmap blockPic;
		int X, Y;
	};
}