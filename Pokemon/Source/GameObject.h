namespace game_framework {
	class  GameObject {
	public:
		virtual void LoadBitMap(int, int, int) = 0;
		virtual void OnShow() = 0;
		virtual void PlayerLeft() = 0;
		virtual void PlayerRight() = 0;
		virtual void PlayerUp() = 0;
		virtual void PlayerDown() = 0;
		virtual void Interact() = 0;
	};
}