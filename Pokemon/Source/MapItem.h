#ifndef MAP_ITEM_H
#define MAP_ITEM_H

#include "MapObject.h"

namespace game_framework {

	class MapItem : public MapObject{
	public:
		MapItem();
		void Interact(); //�binteract��ݭn�B�z����
	private:
	};
}

#endif // !MAP_ITEM_H