#ifndef LEVELS_H
#define LEVELS_H

#include "raylib.h"

namespace game
{
namespace levels
{
const int BRICKS_PER_LINE = 10;
const int BRICKS_PER_COLUMN = 8;
const int TOTAL_DISTANCE_BETWEEN_BRICKS = 50;

struct Brick
{
	Color color;
	Rectangle rec;

	int state;
};

extern Brick layout[BRICKS_PER_COLUMN][BRICKS_PER_LINE];

extern int brickHeight;
extern int brickWidth;
extern int playScreenMinX;
extern int playScreenMaxX;

void InitializeLayout();
void Initialize();
void CheckColissionWithBall();
void Draw();
}
}

#endif
