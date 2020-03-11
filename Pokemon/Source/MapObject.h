#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

namespace game_framework {
	constexpr int STEP = 10;							//移動時每幀移動格數
	class  MapObject {
	public:
		virtual void Interact() = 0;

		virtual void LoadBitMap(int pic, int x, int y) {
			_pic.LoadBitmap(pic);
			X = x;
			Y = y;
		}

		virtual void OnShow() {
			_pic.SetTopLeft(X, Y);
			_pic.ShowBitmap();
		}
		void PlayerDown() {
			Y -= STEP;
		}

		void PlayerUp() {
			Y += STEP;
		}

		void PlayerLeft() {
			X += STEP;
		}

		void PlayerRight() {
			X -= STEP;
		}

		int GetHeight() {
			return _pic.Height();
		}
		
		int GetWidth() {
			return _pic.Width();
		}

	private:
		int X, Y;
		int _height, _width;
		CMovingBitmap _pic;
	};
}
#endif // !MAP_OBJECT_H