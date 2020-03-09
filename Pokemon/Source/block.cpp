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

	void Block::MoveDown() {
		Y -= 40;
	}

	void Block::MoveUp() {
		Y += 40;
	}

	void Block::MoveLeft() {
		X += 40;
	}

	void Block::MoveRight() {
		X -= 40;
	}

	void Block::Interact() {

	}
}