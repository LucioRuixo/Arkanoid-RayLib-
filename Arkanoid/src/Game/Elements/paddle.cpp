#include "paddle.h"

#include "game.h"
#include "Elements/ball.h"

namespace game
{
namespace paddle
{
Paddle paddle;

static float newBallDirectionX;

void Initialize()
{
	paddle.color = RAYWHITE;

	paddle.rec.width = 10.0f * screenWidthScalar;
	paddle.rec.height = 2.0f * screenHeightScalar;
	paddle.rec.x = screenWidth / 2 - paddle.rec.width / 2;
	paddle.rec.y = static_cast<float>(screenHeight / 10 * 9);

	paddle.lives = 3;

	paddle.speed = SPEED;
}

void CheckColissionWithBall()
{
	if (CheckCollisionCircleRec(ball::ball.position, ball::ball.radius, paddle.rec))
	{
		PlaySound(hitSFX);

		ball::ball.up = true;

		newBallDirectionX = (ball::ball.position.x - paddle.rec.x + paddle.rec.width / 2) / 4;
		cout << newBallDirectionX << endl;
		if (newBallDirectionX < ball::MAX_SPEED / 2)
		{
			ball::ball.right = false;
		}
		else
		{
			ball::ball.right = true;
		}

		ball::ball.direction.x = newBallDirectionX;
	}
}

void Draw()
{
	DrawRectangle(static_cast<int>(paddle.rec.x), static_cast<int>(paddle.rec.y), static_cast<int>(paddle.rec.width), static_cast<int>(paddle.rec.height), paddle.color);
}
}
}