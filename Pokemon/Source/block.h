#include "MapObject.h"

namespace game_framework {
	class Block: public MapObject {
	public:
		Block(int);
		void Interact();							// ��ܫ�iĲ�o����
	};
}