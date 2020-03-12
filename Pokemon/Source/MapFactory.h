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
		Map* GetMap(MapName);
		void SetMap_Test();

	private:
		Map** _maps;
		
		int _number_of_maps;
	};
}
#endif // !MAP_FACTORY_H


