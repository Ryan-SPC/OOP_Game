#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "block.h"

constexpr int STEP = 10;							//���ʮɨC�V���ʮ��

namespace game_framework {
	Block::Block(int picID) {
		_picID = picID;
		X = 0;
		Y = 0;
	}

	void Block::Interact() {

	}
}