#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

namespace game
{
namespace paddle
{
const float SPEED;

struct Paddle
{
	Rectangle rec;
	Vector2 position;

	int lives = 3;

	float speed = SPEED;
};

extern Paddle paddle;

void Initialize();
}
}

#endif
