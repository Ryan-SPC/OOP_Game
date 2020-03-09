#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "block.h"
namespace game_framework {
	Block::Block() {

	}

	void Block::LoadBitMap(int pic, int x, int y) {
		blockPic.LoadBitmap(pic);
		X = x;
		Y = y;
	}

	void Block::OnShow() {
		blockPic.SetTopLeft(X, Y);
		blockPic.ShowBitmap();
	}

	void Block::PlayerDown() {
		Y -= 40;
	}

	void Block::PlayerUp() {
		Y += 40;
	}

	void Block::PlayerLeft() {
		X += 40;
	}

	void Block::PlayerRight() {
		X -= 40;
	}

	void Block::Interact() {

	}
}