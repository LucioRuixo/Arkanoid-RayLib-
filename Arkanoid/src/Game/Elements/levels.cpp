#include "levels.h"

#include "game.h"
#include "Elements/ball.h"
#include "Elements/paddle.h"

namespace game
{
namespace levels
{
Brick layout[LAYOUT_HEIGHT][LAYOUT_WIDTH];

int playScreenMinX;
int playScreenMaxX;
int brickHeight;
int brickWidth;

void CheckCollisions()
{
	for (int y = 0; y < LAYOUT_HEIGHT; y++)
	{
		for (int x = 0; x < LAYOUT_WIDTH; x++)
		{
			if (CheckCollisionCircleRec(ball::ball.position, ball::ball.radius, layout[y][x].rec))
			{
				ball::ball.up ? ball::ball.up = false : ball::ball.up = true;
				layout[y][x].state = 0;
			}
		}
	}
}

void Draw()
{
	for (int y = 0; y < LAYOUT_HEIGHT; y++)
	{
		for (int x = 0; x < LAYOUT_WIDTH; x++)
		{
			if (layout[y][x].state == 1)
				DrawRectangle(layout[y][x].rec.x, layout[y][x].rec.y, layout[y][x].rec.width, layout[y][x].rec.height, layout[y][x].color);
		}
	}
}

void Initialize()
{
	playScreenMinX = screenWidth / 8 * 2;
	playScreenMaxX = screenWidth / 8 * 6;
	brickHeight = 25;
	brickWidth = (playScreenMaxX - playScreenMinX - TOTAL_DISTANCE_BETWEEN_BRICKS) / LAYOUT_WIDTH;

	InitializeLayout();
}

void InitializeLayout()
{
	int brickXSum;
	int brickY = 50;

	for (int y = 0; y < LAYOUT_HEIGHT; y++)
	{
		brickXSum = 0;

		for (int x = 0; x < LAYOUT_WIDTH; x++)
		{
			layout[y][x].color = RAYWHITE;

			layout[y][x].rec.width = brickWidth;
			layout[y][x].rec.height = brickHeight;
			layout[y][x].rec.x = playScreenMinX + TOTAL_DISTANCE_BETWEEN_BRICKS / (LAYOUT_WIDTH) + brickXSum;
			layout[y][x].rec.y = brickY;

			layout[y][x].state = 1;

			brickXSum += brickWidth + TOTAL_DISTANCE_BETWEEN_BRICKS / (LAYOUT_WIDTH + 1);
		}

		brickY += brickHeight + TOTAL_DISTANCE_BETWEEN_BRICKS / (LAYOUT_WIDTH + 1);
	}
}
}
}