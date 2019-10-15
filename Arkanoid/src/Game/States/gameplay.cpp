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
Rectangle pauseMenu;

static void CheckCollisions()
{
	levels::CheckColissionWithBall();
	paddle::CheckColissionWithBall();
}

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
			ball::ball.direction.x = 0;
		}
	}

	if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && paddle::paddle.rec.x > levels::playScreenMinX)
		paddle::paddle.rec.x -= paddle::paddle.speed * screenWidthScalar * deltaTime;

	if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && paddle::paddle.rec.x + paddle::paddle.rec.width < levels::playScreenMaxX)
		paddle::paddle.rec.x += paddle::paddle.speed * screenWidthScalar * deltaTime;
}

static bool CheckVictory()
{
	for (int y = 0; y < levels::LAYOUT_HEIGHT; y++)
	{
		for (int x = 0; x < levels::LAYOUT_WIDTH; x++)
		{
			if (levels::layout[y][x].state == 1)
				return false;
		}
	}

	return true;
}

void Initialize()
{
	pauseMenu.width = 20 * screenWidthScalar;
	pauseMenu.height = 10 * screenHeightScalar;
	pauseMenu.x = (screenWidth / 2 - pauseMenu.width / 2) * screenWidthScalar;
	pauseMenu.y = (screenHeight / 2 - pauseMenu.height / 2) * screenHeightScalar;

	levels::Initialize();
	paddle::Initialize();
	ball::Initialize();
}

void Update()
{
	UpdateButton(pause);

	if (paddle::paddle.lives > 0)
	{
		if(CheckVictory())
			currentGameState = GameState::GameOver;

		Input();

		CheckCollisions();

		ball::Movement();
	}
	else
	{
		currentGameState = GameState::GameOver;
	}
}

void Draw()
{
	DrawText(TextFormat("Lives:"), static_cast<int>(1.0f * screenWidthScalar), static_cast<int>(1.0f * screenHeightScalar), 30, RAYWHITE);
	DrawText(TextFormat("%i", paddle::paddle.lives), static_cast<int>(1.0f * screenWidthScalar), static_cast<int>(5.0f * screenHeightScalar), 40, RAYWHITE);
	DrawPlayScreenLimits();
	levels::Draw();
	paddle::Draw();
	ball::Draw();
}
}
}