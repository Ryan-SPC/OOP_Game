namespace game_framework {
	class  GameObject {
	public:
		virtual void LoadBitMap(int, int, int) = 0;
		virtual void OnShow() = 0;
		virtual void MoveLeft() = 0;
		virtual void MoveRight() = 0;
		virtual void MoveUp() = 0;
		virtual void MoveDown() = 0;
		virtual void Interact() = 0;
	};
}