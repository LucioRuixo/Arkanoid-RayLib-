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
	Pause
};

struct Button
{
	Function function;
	GameState state;
	Rectangle rec;

	const char* text;

	bool cursorOverButton;
};

extern Button continue_;
extern Button exit;
extern Button fullScreen_;
extern Button pause;
extern Button play;
extern Button return_;

void CheckButtonPressing(Button button);
void DrawButton(Button button);
namespace main_menu
{
	void InitializeButtons(Button &exit, Button &fullScreen_, Button &play);
}
namespace gameplay
{
	void InitializeButtons(Button &continue_, Button &pause, Button return_);
}
namespace game_over
{
	void InitializeButtons(Button return_);
}
void UpdateButton(Button &button);

bool CursorOverButton(Button button);
}

#endif