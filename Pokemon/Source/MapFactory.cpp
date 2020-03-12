#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "MapFactory.h"
#include "block.h"

namespace game_framework {
	
	MapFactory::MapFactory() :_number_of_maps(5) {				// �w�]map�ƶq��5
		/// �t�m�O���� ///
		_maps = new Map*[_number_of_maps];
		for (int i = 0; i < _number_of_maps; i++) {
			_maps[i] = new Map();
		}

		/// �]�w�Ҧ��a�� ///
		// �C��s�W�a�ϴN�n�[�J�s��SetMap_XXX()�禡
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
		map->SetPic(IDB_MAP, 600, 960);				// ����map�Ϥ��ιϤ�size

		/////�榸�[�J/////
		map->SetObject(new Block(IDB_BLOCK), 0, 0); // �N��ê���[�Jmap�x�}��m(0,0)���a��

		/////�j��[�J/////
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