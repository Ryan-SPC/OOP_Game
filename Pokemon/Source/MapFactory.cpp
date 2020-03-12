#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "MapFactory.h"

namespace game_framework {
	
	MapFactory::MapFactory() :_number_of_maps(10) {				// 預設map數量為10
		_maps = new Map[_number_of_maps];
		SetMap_Test();
	}

	MapFactory::~MapFactory() {
		delete[] _maps;
	}

	Map MapFactory::GetMap(MapName name) {
		return _maps[name];
	}

	void MapFactory::SetMap_Test() {
		Map map = _maps[Test];
	}
}