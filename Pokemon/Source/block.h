#include "MapObject.h"

namespace game_framework {
	class Block: public MapObject {
	public:
		Block(int);
		void Interact();							// 對話後可觸發項目
	};
}