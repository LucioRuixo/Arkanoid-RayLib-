#include "game.h"

#include "Elements/buttons.h"
#include "Elements/levels.h"
#include "Elements/paddle.h"
#include "States/main_menu.h"
#include "States/gameplay.h"
#include "States/game_over.h"

namespace game
{
static double oldTime;
static double time;

GameState currentGameState;
Vector2 cursor;

bool fullscreenOn;
bool gameShouldClose;

int screenHeight;
int screenWidth;

float deltaTime;
float screenHeightScalar;
float screenWidthScalar;

static void Initialize()
{
	currentGameState = GameState::MainMenu;
	cursor = GetMousePosition();

	fullscreenOn = false;
	gameShouldClose = false;

	screenWidth = WINDOW_WIDTH;
	screenWidthScalar = static_cast<float>(screenWidth) / 100;
	screenHeight = WINDOW_HEIGHT;
	screenHeightScalar = static_cast<float>(screenHeight) / 100;

	deltaTime = 0;

	oldTime = 0;
	time = 0;

	InitWindow(screenWidth, screenHeight, "ARKANOID!");
	main_menu::InitializeButtons();
	gameplay::Initialize();
	game_over::InitializeButtons();
	SetTargetFPS(60);
}

static void Update()
{
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
	ClearBackground(BLACK);

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