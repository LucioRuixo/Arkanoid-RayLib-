#include "game.h"

#include "States/main_menu.h"
#include "States/gameplay.h"
#include "States/game_over.h"
#include "Elements/buttons.h"
#include <iostream>
using namespace std;

namespace game
{
static double oldTime;
static double time;

GameState currentGameState;
Vector2 cursor;

bool fullscreenOn;
bool gameShouldClose;

int screenWidth;
int screenHeight;

float deltaTime;

static void Initialize()
{
	currentGameState = GameState::MainMenu;
	cursor = GetMousePosition();

	fullscreenOn = false;
	gameShouldClose = false;

	screenWidth = 1280;
	screenHeight = 720;

	deltaTime = 0;

	oldTime = 0;
	time = 0;

	InitWindow(screenWidth, screenHeight, "ARKANOID!");
	main_menu::InitializeButtons(exit, fullScreen_, play);
	gameplay::InitializeButtons(continue_, pause, return_);
	game_over::InitializeButtons(return_);
	SetTargetFPS(60);
}

static void Update()
{
	cout << GetMonitorCount() << ", " << GetMonitorWidth(0) << "x" << GetMonitorHeight(0) << endl;

	cursor = GetMousePosition();

	UpdateDeltaTime();

	switch (currentGameState)
	{
	case GameState::MainMenu:
	{
		main_menu::Update();
		break;
	}
	case GameState::Gameplay:
	{
		gameplay::Update();
		break;
	}
	case GameState::GameOver:
	{
		game_over::Update();
		break;
	}
	}
}

static void Draw()
{
	BeginDrawing();

	switch (currentGameState)
	{
	case GameState::MainMenu:
	{
		main_menu::Draw();
		break;
	}
	case GameState::Gameplay:
	{
		gameplay::Draw();
		break;
	}
	case GameState::GameOver:
	{
		game_over::Draw();
		break;
	}
	}

	EndDrawing();
}

static void Close()
{
	CloseWindow();
}

void Execute()
{
	Initialize();

	while (!gameShouldClose)
	{
		if (!WindowShouldClose())
		{
			Update();

			Draw();
		}
		else
			gameShouldClose = true;
	}

	Close();
}

void UpdateDeltaTime()
{
	time = GetTime();
	deltaTime = static_cast<float>(time - oldTime);
	oldTime = time;
}
}