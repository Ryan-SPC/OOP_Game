#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include "Map.h"
namespace game_framework {
	class MapFactory {
	public:
		MapFactory() {};
		void SetMapOne() {};
		Map M1() {};

	private:
		Map* map1;
	};
}
#endif // !MAP_FACTORY_H


