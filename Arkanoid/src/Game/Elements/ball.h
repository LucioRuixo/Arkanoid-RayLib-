#ifndef BALL_H
#define BALL_H

#include "raylib.h"

namespace game
{
namespace ball
{
const float SPEED;

struct Ball
{
	Vector2 direction;
	Vector2 position;
	
	float radius;
	float speed = SPEED;
};

extern Ball ball;

void Initialize();
}
}

#endif
