#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "block.h"

constexpr int STEP = 10;							//���ʮɨC�V���ʮ��

namespace game_framework {
	Block::Block() {
		
	}

	/*void Block::LoadBitMap(int pic, int x, int y) {
		blockPic.LoadBitmap(pic);
		X = x;
		Y = y;
	}

	void Block::OnShow() {
		blockPic.SetTopLeft(X, Y);
		blockPic.ShowBitmap();
	}

	void Block::PlayerDown() {
		Y -= STEP;
	}

	void Block::PlayerUp() {
		Y += STEP;
	}

	void Block::PlayerLeft() {
		X += STEP;
	}

	void Block::PlayerRight() {
		X -= STEP;
	}*/

	void Block::Interact() {

	}
}