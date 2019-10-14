#include "paddle.h"

#include "game.h"

namespace game
{
namespace paddle
{
Paddle paddle;

void Draw()
{
	DrawRectangle(paddle.rec.x, paddle.rec.y, paddle.rec.width, paddle.rec.height, paddle.color);
}

void Initialize()
{
	paddle.color = RAYWHITE;

	paddle.rec.width = 10.0f * screenWidthScalar;
	paddle.rec.height = 2.0f * screenHeightScalar;
	paddle.rec.x = screenWidth / 2 - paddle.rec.width / 2;
	paddle.rec.y = (screenHeight / 10 * 9);

	paddle.lives = 3;

	paddle.speed = SPEED;
}
}
}