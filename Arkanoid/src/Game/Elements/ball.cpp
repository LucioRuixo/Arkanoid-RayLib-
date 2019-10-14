#include "ball.h"

#include "game.h"
#include "Elements/paddle.h"

namespace game
{
namespace ball
{
Ball ball;

void Draw()
{
	DrawCircle(ball.position.x, ball.position.y, ball.radius, ball.color);
}

void Initialize()
{
	ball.color = RAYWHITE;

	ball.radius = 5 * screenWidthScalar;

	ball.position.x = screenWidth / 2;
	ball.position.y = (paddle::paddle.rec.y - ball.radius / 2) * screenHeightScalar;

	ball.still = true;
	ball.right = true;
	ball.up = true;

	ball.speed = 5;
}
}
}