#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include "Map.h"
namespace game_framework {
	enum MapName
	{
		Test
	};
	
	class MapFactory {
	public:
		MapFactory();
		~MapFactory();
		Map GetMap(MapName);

	private:
		Map* _maps;
		void SetMap_Test();
		int _number_of_maps;
	};
}
#endif // !MAP_FACTORY_H


