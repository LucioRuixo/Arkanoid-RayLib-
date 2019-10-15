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

Music music;

Sound buttonSFX;
Sound hitSFX;

bool fullscreenOn;
bool gameShouldClose;

int screenHeight;
int screenWidth;

float deltaTime;
float screenHeightScalar;
float screenWidthScalar;

static void InitializeSounds()
{
	music = LoadMusicStream("audio/music/music.ogg");

	buttonSFX = LoadSound("audio/SFX/buttonSFX.ogg");
	hitSFX = LoadSound("audio/SFX/hitSFX.ogg");
}

static void Initialize()
{
	currentGameState = GameState::MainMenu;
	cursor = GetMousePosition();

	fullscreenOn = false;
	gameShouldClose = false;

	screenWidth = WINDOW_WIDTH;
	screenWidthScalar = static_cast<float>(screenWidth) / 100.0f;
	screenHeight = WINDOW_HEIGHT;
	screenHeightScalar = static_cast<float>(screenHeight) / 100.0f;

	deltaTime = 0;

	oldTime = 0;
	time = 0;

	InitWindow(screenWidth, screenHeight, "ARKANOID!");
	SetExitKey(KEY_P);
	InitAudioDevice();
	InitializeSounds();
	buttons::main_menu::InitializeButtons();
	gameplay::Initialize();
	buttons::game_over::InitializeButtons();
	SetTargetFPS(60);
}

static void Input()
{
	if (IsKeyPressed(KEY_M))
	{
		if (IsMusicPlaying(music))
			PauseMusicStream(music);
		else
			ResumeMusicStream(music);
	}
}

static void Update()
{
	UpdateDeltaTime();

	UpdateMusicStream(music);

	cursor = GetMousePosition();

	Input();

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

static void UnloadSounds()
{
	UnloadMusicStream(music);

	UnloadSound(buttonSFX);
	UnloadSound(hitSFX);
}

static void Close()
{
	UnloadSounds();
	CloseAudioDevice();
	CloseWindow();
}

void Execute()
{
	Initialize();
	PlayMusicStream(music);

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

	StopMusicStream(music);
	Close();
}

void UpdateDeltaTime()
{
	time = GetTime();
	deltaTime = static_cast<float>(time - oldTime);
	oldTime = time;
}
}