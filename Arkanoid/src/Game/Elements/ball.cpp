#include "ball.h"

#include "game.h"
#include "Elements/paddle.h"

namespace game
{
namespace ball
{
Ball ball;

void Initialize()
{
	ball.color = RAYWHITE;

	ball.radius = 1 * screenWidthScalar;

	ball.position.x = static_cast<float>(screenWidth) / 2;
	ball.position.y = paddle::paddle.rec.y - paddle::paddle.rec.height / 2 - ball.radius;

	ball.still = true;
	ball.right = true;
	ball.up = true;
}

void Movement()
{
	if (ball.direction.x > MAX_SPEED)
		ball.direction.x = MAX_SPEED;
	ball.direction.y = MAX_SPEED - ball.direction.x;

	if (ball.still)
	{
		ball.position.x = paddle::paddle.rec.x + paddle::paddle.rec.width / 2;
		ball.position.y = paddle::paddle.rec.y - paddle::paddle.rec.height / 2 - ball.radius;
	}
	else
	{
		ball.right ? ball.position.x += ball.direction.x * screenWidthScalar * deltaTime : ball.position.x -= ball.direction.x * screenWidthScalar * deltaTime;
		ball.up ? ball.position.y -= ball.direction.y * screenHeightScalar * deltaTime : ball.position.y += ball.direction.y * screenHeightScalar * deltaTime;
	}
}

void Draw()
{
	DrawCircle(static_cast<int>(ball.position.x), static_cast<int>(ball.position.y), ball.radius, ball.color);
}
}
}