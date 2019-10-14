#ifndef BALL_H
#define BALL_H

#include "raylib.h"

namespace game
{
namespace ball
{
struct Ball
{
	Color color;
	Vector2 direction;
	Vector2 position;
	
	bool still;
	bool right;
	bool up;

	float radius;
	float speed;
};

extern Ball ball;

void Draw();
void Initialize();
}
}

#endif
