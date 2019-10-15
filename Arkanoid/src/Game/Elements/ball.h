#ifndef BALL_H
#define BALL_H

#include "raylib.h"

namespace game
{
namespace ball
{
	const float MAX_SPEED = 75;

struct Ball
{
	Color color;
	Vector2 direction;
	Vector2 position;
	
	bool still;
	bool right;
	bool up;

	float radius;
};

extern Ball ball;

void Draw();
void Initialize();
void Movement();
}
}

#endif
