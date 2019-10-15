#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

namespace game
{
namespace paddle
{
const float SPEED = 25;

struct Paddle
{
	Color color;
	Rectangle rec;

	int lives;

	float speed;
};

extern Paddle paddle;

void CheckColissionWithBall();
void Draw();
void Initialize();
}
}

#endif
