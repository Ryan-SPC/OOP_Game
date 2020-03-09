#define CENTER_X 320						//設定中心點XY值
#define CENTER_Y 200
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
//The window is 640x400
namespace game_framework {
	
	class Player {
	public:
		Player();
		void LoadBitMap();
		void OnShow();
		void OnMove();
		int Direction;
		const int X, Y;
		int GetHeight();
		int GetWidth();
	private:
		CMovingBitmap *playerShow;
		CMovingBitmap playerDown;
		CMovingBitmap playerUp;
		CMovingBitmap playerLeft;
		CMovingBitmap playerRight;
	};
}