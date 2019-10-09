#ifndef GAME_H
#define GAME_H

#include "raylib.h"

namespace game
{
const int PLADDLE_SPEED = 5;
const int BALL_SPEED = 5;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

enum GameState
{
	MainMenu,
	Gameplay,
	GameOver
};

extern GameState currentGameState;
extern Vector2 cursor;

extern bool fullscreenOn;
extern bool gameShouldClose;

extern int screenWidth; //9
extern int screenHeight; //16

extern float deltaTime;

void Execute();

void UpdateDeltaTime();
}

#endif