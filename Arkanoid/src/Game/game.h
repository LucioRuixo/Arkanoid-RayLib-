#ifndef GAME_H
#define GAME_H

#include "raylib.h"

namespace game
{
const int PLADDLE_SPEED = 5;
const int BALL_SPEED = 5;
const int WINDOW_HEIGHT = 720;
const int WINDOW_WIDTH = 1280;

enum GameState
{
	MainMenu,
	CreditsScreen,
	Gameplay,
	GameOver
};

extern GameState currentGameState;
extern Vector2 cursor;

extern Music music;

extern Sound buttonSFX;
extern Sound hitSFX;

extern bool fullscreenOn;
extern bool gameShouldClose;

extern int screenWidth;
extern int screenHeight;

extern float deltaTime;
extern float screenHeightScalar;
extern float screenWidthScalar;

void Execute();

void UpdateDeltaTime();
}

#endif