#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include "Map.h"
namespace game_framework {
	/// �w�q�a�ϦW�� ///
	enum MapName
	{
		Test
	};
	
	class MapFactory {
	public:
		MapFactory();
		~MapFactory();
		Map* GetMap(MapName);		// �^�ǫ��w�W�٪��a��					

	private:
		Map** _maps;				// �ΨӦs�� *Map ��Array		
		int _number_of_maps;		// _maps��size (�ѩ�O��Array�s*Map �ҥH�ݭn�w�]size)
		void SetMap_Test();			// ��_maps[Test]�i��]�w
	};
}
#endif // !MAP_FACTORY_H


