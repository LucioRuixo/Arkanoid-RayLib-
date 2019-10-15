#ifndef BUTTONS_H
#define BUTTONS_H

#include "raylib.h"

#include "game.h"

namespace game
{
namespace buttons
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

namespace main_menu
{
	void InitializeButtons();
}
namespace game_over
{
	void InitializeButtons();
}
void CheckButtonPressing(Button button);
void UpdateButton(Button &button);
void DrawButton(Button button);

bool CursorOverButton(Button button);
}
}

#endif