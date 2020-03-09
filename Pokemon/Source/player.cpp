#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "player.h"

namespace game_framework {
	Player::Player():X(CENTER_X), Y(CENTER_Y){
		Direction = DOWN;
	}

	void Player::LoadBitMap() {
		playerDown.LoadBitmap(IDB_PLAYER, RGB(255, 255, 255));
		playerUp.LoadBitmap(IDB_PLAYER_BACK, RGB(255, 255, 255));
		playerLeft.LoadBitmap(IDB_PLAYER_LEFT, RGB(255, 255, 255));
		playerRight.LoadBitmap(IDB_PLAYER_RIGHT, RGB(255, 255, 255));
		playerShow = &playerDown;
	}
	void Player::OnShow() {
		playerShow->SetTopLeft(X, Y);
		playerShow->ShowBitmap();
	}

	void Player::OnMove() {
		switch (Direction)
		{
		case LEFT:			
			playerShow = &playerLeft;
			break;
		case UP:
			playerShow = &playerUp;
			break;
		case RIGHT:
			playerShow = &playerRight;
			break;
		case DOWN:
			playerShow = &playerDown;
			break;
		default:
			break;
		}
	}

	int Player::GetHeight(){
		return playerDown.Height();
	}

	int Player::GetWidth() {
		return playerDown.Width();
	}
}