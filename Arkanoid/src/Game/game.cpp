#include "game.h"

#include "States/main_menu.h"
#include "States/gameplay.h"
#include "States/game_over.h"

namespace game
{
static double oldTime;
static double time;

GameState currentGameState;
Vector2 cursor;

float deltaTime;

static void Initialize()
{
	currentGameState = GameState::MainMenu;
	cursor = GetMousePosition();

	deltaTime = 0;

	oldTime = 0;
	time = 0;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - keyboard input");
	SetTargetFPS(60);
}

static void Update()
{
	BeginDrawing();

	while (!WindowShouldClose())
	{
		switch (currentGameState)
		{
		case GameState::MainMenu:
		{
			main_menu::Execute();
			break;
		}
		case GameState::Gameplay:
		{
			gameplay::Execute();
			break;
		}
		case GameState::GameOver:
		{
			game_over::Execute();
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