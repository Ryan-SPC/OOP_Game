#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include "Map.h"
namespace game_framework {
	/// 定義地圖名稱 ///
	enum MapName
	{
		Test
	};
	
	class MapFactory {
	public:
		MapFactory();
		~MapFactory();
		Map* GetMap(MapName);		// 回傳指定名稱的地圖					

	private:
		Map** _maps;				// 用來存放 *Map 的Array		
		int _number_of_maps;		// _maps的size (由於是用Array存*Map 所以需要預設size)
		void SetMap_Test();			// 對_maps[Test]進行設定
	};
}
#endif // !MAP_FACTORY_H


