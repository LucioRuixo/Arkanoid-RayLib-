#ifndef GAME_H
#define GAME_H

#include "raylib.h"

namespace game
{
const int SCREEN_WIDTH = 1280; //9
const int SCREEN_HEIGHT = 720; //16
const int PLADDLE_SPEED = 5;
const int BALL_SPEED = 5;

enum GameState
{
	MainMenu,
	Gameplay,
	GameOver
};

extern GameState currentGameState;
extern Vector2 cursor;

extern float deltaTime;

void Execute();

void UpdateDeltaTime();
}

#endif