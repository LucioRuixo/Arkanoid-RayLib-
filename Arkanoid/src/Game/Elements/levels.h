#ifndef LEVELS_H
#define LEVELS_H

#include "raylib.h"

namespace game
{
namespace levels
{
const int TOTAL_DISTANCE_BETWEEN_BRICKS = 50;
const int LAYOUT_WIDTH = 10;
const int LAYOUT_HEIGHT = 8;

struct Brick
{
	Color color;
	Rectangle rec;

	int state;
};

extern Brick layout[LAYOUT_HEIGHT][LAYOUT_WIDTH];

extern int playScreenMinX;
extern int playScreenMaxX;
extern int brickHeight;
extern int brickWidth;

void CheckCollisions();
void Draw();
void Initialize();
void InitializeLayout();
}
}

#endif
