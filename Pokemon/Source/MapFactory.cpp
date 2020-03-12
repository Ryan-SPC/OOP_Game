#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "MapFactory.h"
#include "block.h"

namespace game_framework {
	
	MapFactory::MapFactory() :_number_of_maps(5) {				// 預設map數量為5
		/// 配置記憶體 ///
		_maps = new Map*[_number_of_maps];
		for (int i = 0; i < _number_of_maps; i++) {
			_maps[i] = new Map();
		}

		/// 設定所有地圖 ///
		// 每當新增地圖就要加入新的SetMap_XXX()函式
		SetMap_Test();
	}

	MapFactory::~MapFactory() {
		for (int i = 0; i < _number_of_maps; i++)
			delete _maps[i];
		delete[] _maps;
	}

	Map* MapFactory::GetMap(MapName name) {
		return _maps[name];
	}

	void MapFactory::SetMap_Test() {	
		Map* map = _maps[Test];
		map->SetPic(IDB_MAP, 600, 960);				// 給予map圖片及圖片size

		/////單次加入/////
		map->SetObject(new Block(IDB_BLOCK), 0, 0); // 將障礙物加入map矩陣位置(0,0)的地方

		/////迴圈加入/////
		for (int i = 1; i < 6; i++) {
			for (int j = 1; j < 6; j++) {
				if (i != 5) {
					map->SetObject(new Block(IDB_BLOCK), i, 5);
					break;
				}
				else
					map->SetObject(new Block(IDB_BLOCK), i, j);
			}
		}
	}
}