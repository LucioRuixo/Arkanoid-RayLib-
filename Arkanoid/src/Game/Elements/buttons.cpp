#include "buttons.h"

#include "game.h"
#include <iostream>
using namespace std;

namespace game
{
Button continue_;
Button exit;
Button fullScreen_;
Button pause;
Button play;
Button return_;

void CheckButtonPressing(Button button)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		switch (button.function)
		{
		case Function::ChangeState:
			currentGameState = button.state;
			break;
		case Function::ExitGame:
			gameShouldClose = true;
			break;
		case Function::Pause:
			//pauseActive ? pauseActive = false : pauseActive = true;
			break;
		case Function::ActivateFullscreen:
			if (!fullscreenOn)
			{
				screenWidth = GetMonitorWidth(0);
				screenHeight = GetMonitorHeight(0);
				ToggleFullscreen();
			}
			else
			{
				screenWidth = WINDOW_WIDTH;
				screenHeight = WINDOW_HEIGHT;
				ToggleFullscreen();
			}
			break;
		}
	}
}

void DrawButton(Button button)
{
	if (button.cursorOverButton)
	{
		DrawRectangle(static_cast<int>(button.rec.x), static_cast<int>(button.rec.y), static_cast<int>(button.rec.width), static_cast<int>(button.rec.height), RAYWHITE);
		DrawText(button.text, static_cast<int>(button.rec.x + 5), static_cast<int>(button.rec.y + 5), 20, BLACK);
	}
	else
		DrawText(button.text, static_cast<int>(button.rec.x + 5), static_cast<int>(button.rec.y + 5), 20, RAYWHITE);
}

namespace main_menu
{
void InitializeButtons(Button &exit, Button &fullScreen_, Button &play)
{
	exit.function = Function::ExitGame;
	exit.rec.width = 60 * screenWidthScalar;
	exit.rec.height = 30 * screenHeightScalar;
	exit.rec.x = static_cast<float>(screenWidth) / 2 - 20;
	exit.rec.y = static_cast<float>(screenHeight) / 2 + 115;
	exit.text = "Exit";

	fullScreen_.function = Function::ActivateFullscreen;
	fullScreen_.rec.width = 190 * screenWidthScalar;
	fullScreen_.rec.height = 30 * screenHeightScalar;
	fullScreen_.rec.x = screenWidth - fullScreen_.rec.width - 10 * screenWidthScalar;
	fullScreen_.rec.y = 10 * screenHeightScalar;
	fullScreen_.text = "Fullscreen";
	cout << "Fullscreen: width " << fullScreen_.rec.width;

	play.function = Function::ChangeState;
	play.state = GameState::Gameplay;
	play.rec.width = 80 * screenWidthScalar;
	play.rec.height = 30 * screenHeightScalar;
	play.rec.x = static_cast<float>(screenWidth) / 2 - 35 * screenWidthScalar;
	play.rec.y = static_cast<float>(screenHeight) / 2 + 45 * screenHeightScalar;
	play.text = "PLAY";
}
}

namespace gameplay
{
void InitializeButtons(Button &continue_, Button &pause, Button return_)
{
	continue_.function = Function::Pause;
	continue_.rec.width = 110 * screenWidthScalar;
	continue_.rec.height = 30 * screenHeightScalar;
	continue_.rec.x = screenWidth / 2 - continue_.rec.width / 2;
	//continue_.rec.y = screenHeight / 2 - continue_.rec.height / 2 - ((pauseMenu.rec.height - continue_.rec.height * 3) / 4 + continue_.rec.height);
	continue_.text = "Continuar";

	pause.function = Function::Pause;
	pause.rec.width = 95 * screenWidthScalar;
	pause.rec.height = 30 * screenHeightScalar;
	pause.rec.x = 10 * screenWidthScalar;
	pause.rec.y = 10 * screenHeightScalar;
	pause.text = "|| Pausa";

	return_.function = Function::ChangeState;
	return_.state = GameState::MainMenu;
	return_.rec.width = 95 * screenWidthScalar;
	return_.rec.height = 30 * screenHeightScalar;
	return_.rec.x = 10 * screenWidthScalar;
	return_.rec.y = 10 * screenHeightScalar;
	return_.text = "< Return";
}
}

namespace game_over
{
	void InitializeButtons(Button return_)
	{
		return_.function = Function::ChangeState;
		return_.state = GameState::MainMenu;
		return_.rec.width = 95 * screenWidthScalar;
		return_.rec.height = 30 * screenHeightScalar;
		return_.rec.x = 10 * screenWidthScalar;
		return_.rec.y = 10 * screenHeightScalar;
		return_.text = "< Return";
	}
}

void UpdateButton(Button &button)
{
	if (CursorOverButton(button))
	{
		button.cursorOverButton = true;

		CheckButtonPressing(button);
	}
	else
		button.cursorOverButton = false;
}

bool CursorOverButton(Button button)
{
	if ((cursor.x > button.rec.x && cursor.x < button.rec.x + button.rec.width)
		&&
		(cursor.y > button.rec.y && cursor.y < button.rec.y + button.rec.height))
	{
		return true;
	}
	else
		return false;
}
}