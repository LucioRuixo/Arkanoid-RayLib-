#ifndef BUTTONS_H
#define BUTTONS_H

#include "raylib.h"

#include "game.h"

namespace game
{
enum Function
{
	ActivateFullscreen,
	ChangeState,
	ExitGame,
};

struct Button
{
	Function function;
	GameState state;
	Rectangle rec;

	const char* text;

	bool cursorOverButton;
};

extern Button exit;
extern Button fullScreen_;
extern Button pause;
extern Button play;
extern Button return_;

extern float buttonsX;

void CheckButtonPressing(Button button);
void DrawButton(Button button);
namespace main_menu
{
	void InitializeButtons();
}
namespace game_over
{
	void InitializeButtons();
}
void UpdateButton(Button &button);

bool CursorOverButton(Button button);
}

#endif