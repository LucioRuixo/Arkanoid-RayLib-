#include "game.h"

namespace game
{
static double oldTime;
static double time;

static void Initialize()
{
	GameState currentGameState = GameState::MainMenu;
	Vector2 cursor;

	deltaTime = 0;
	oldTime = 0;
	time = 0;

	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - keyboard input");
}

static void Update()
{
	while (!WindowShouldClose())
	{
		switch (currentGameState)
		{
		case GameState::MainMenu:
		{
			main_menu::Execute;
			break;
		}
		case GameState::Gameplay:
		{
			gameplay::Execute;
			break;
		}
		case GameState::GameOver:
		{
			game_over::Execute;
			break;
		}
		}
	}
}

static void Close()
{
	CloseWindow();
}

void Execute()
{
	Initialize();
	Update();
	Close();
}

void UpdateDeltaTime()
{
	time = GetTime();
	deltaTime = static_cast<float>(time - oldTime);
	oldTime = time;
}
}