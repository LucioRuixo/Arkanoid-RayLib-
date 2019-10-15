#include "levels.h"

#include "game.h"
#include "Elements/ball.h"
#include "Elements/paddle.h"

namespace game
{
namespace levels
{
Brick layout[BRICKS_PER_COLUMN][BRICKS_PER_LINE];

int brickHeight;
int brickWidth;
int playScreenMinX;
int playScreenMaxX;

void InitializeLayout()
{
	int brickXSum;
	int brickY = 50;

	for (int y = 0; y < BRICKS_PER_COLUMN; y++)
	{
		brickXSum = 0;

		for (int x = 0; x < BRICKS_PER_LINE; x++)
		{
			layout[y][x].color = RAYWHITE;

			layout[y][x].rec.width = static_cast<float>(brickWidth);
			layout[y][x].rec.height = static_cast<float>(brickHeight);
			layout[y][x].rec.x = static_cast<float>(playScreenMinX) + static_cast<float>(TOTAL_DISTANCE_BETWEEN_BRICKS) / static_cast<float>(BRICKS_PER_LINE) + static_cast<float>(brickXSum);
			layout[y][x].rec.y = static_cast<float>(brickY);

			layout[y][x].state = 1;

			brickXSum += brickWidth + TOTAL_DISTANCE_BETWEEN_BRICKS / (BRICKS_PER_LINE + 1);
		}

		brickY += brickHeight + TOTAL_DISTANCE_BETWEEN_BRICKS / (BRICKS_PER_LINE + 1);
	}
}

void Initialize()
{
	playScreenMinX = screenWidth / 8 * 2;
	playScreenMaxX = screenWidth / 8 * 6;
	brickHeight = 25;
	brickWidth = (playScreenMaxX - playScreenMinX - TOTAL_DISTANCE_BETWEEN_BRICKS) / BRICKS_PER_LINE;

	InitializeLayout();
}

void CheckColissionWithBall()
{
	if (ball::ball.position.x - ball::ball.radius <= playScreenMinX)
	{
		PlaySound(hitSFX);
		ball::ball.right = true;
	}

	if (ball::ball.position.x + ball::ball.radius >= playScreenMaxX)
	{
		PlaySound(hitSFX);
		ball::ball.right = false;
	}

	if (ball::ball.position.y - ball::ball.radius <= 0)
	{
		PlaySound(hitSFX);
		ball::ball.up = false;
	}

	if (ball::ball.position.y + ball::ball.radius > screenHeight)
	{
		PlaySound(hitSFX);
		paddle::paddle.lives--;

		ball::ball.up = true;
		ball::ball.still = true;
	}

	for (int y = 0; y < BRICKS_PER_COLUMN; y++)
	{
		for (int x = 0; x < BRICKS_PER_LINE; x++)
		{
			if (layout[y][x].state == 1 && CheckCollisionCircleRec(ball::ball.position, ball::ball.radius, layout[y][x].rec))
			{
				PlaySound(hitSFX);

				ball::ball.up = false;
				layout[y][x].state = 0;
			}
		}
	}
}

void Draw()
{
	for (int y = 0; y < BRICKS_PER_COLUMN; y++)
	{
		for (int x = 0; x < BRICKS_PER_LINE; x++)
		{
			if (layout[y][x].state == 1)
				DrawRectangle(static_cast<int>(layout[y][x].rec.x), static_cast<int>(layout[y][x].rec.y), static_cast<int>(layout[y][x].rec.width), static_cast<int>(layout[y][x].rec.height), layout[y][x].color);
		}
	}
}
}
}