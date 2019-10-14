#include "gameplay.h"

#include "raylib.h"

#include "Elements/ball.h"
#include "Elements/buttons.h"
#include "Elements/levels.h"
#include "Elements/paddle.h"

namespace game
{
namespace gameplay
{
static void DrawPlayScreenLimits()
{
	DrawLine(levels::playScreenMinX, 0, levels::playScreenMinX, screenHeight - 1, RAYWHITE);
	DrawLine(levels::playScreenMaxX, 0, levels::playScreenMaxX, screenHeight - 1, RAYWHITE);
}

static void Input()
{
	if (ball::ball.still)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			ball::ball.still = false;
			ball::ball.direction = {5 * ball::ball.speed * screenWidthScalar * deltaTime, 5 * ball::ball.speed * screenHeightScalar * deltaTime};
		}
	}

	if (IsKeyDown(KEY_LEFT))
		paddle::paddle.rec.x -= paddle::paddle.speed * screenWidthScalar * deltaTime;

	if (IsKeyDown(KEY_RIGHT))
		paddle::paddle.rec.x += paddle::paddle.speed * screenWidthScalar * deltaTime;
}

void Initialize()
{
	InitializeButtons();
	levels::Initialize();
	paddle::Initialize();
	ball::Initialize();
}

void Update()
{
	Input();
}

void Draw()
{
	DrawPlayScreenLimits();
	levels::Draw();
	paddle::Draw();
	ball::Draw();
}
}
}