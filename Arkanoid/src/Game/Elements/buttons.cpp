#include "buttons.h"

#include "game.h"

namespace game
{
namespace buttons
{
Button exit;
Button fullScreen_;
Button pause;
Button play;
Button return_;

float buttonsX;

namespace main_menu
{
	void InitializeButtons()
	{
		buttonsX = static_cast<float>(screenWidth) / 6.0f;

		exit.function = Function::ExitGame;
		exit.rec.width = 4.0f * screenWidthScalar;
		exit.rec.height = 4.0f * screenHeightScalar;
		exit.rec.x = buttonsX;
		exit.rec.y = (static_cast<float>(screenHeight) / 3.0f) * 2 + 40;
		exit.text = "Exit";

		fullScreen_.function = Function::ActivateFullscreen;
		fullScreen_.rec.width = 10.0f * screenWidthScalar;
		fullScreen_.rec.height = 4.0f * screenHeightScalar;
		fullScreen_.rec.x = screenWidth - fullScreen_.rec.width - 1.0f * screenWidthScalar;
		fullScreen_.rec.y = 1.0f * screenHeightScalar;
		fullScreen_.text = "Fullscreen";
		cout << "Fullscreen: width " << fullScreen_.rec.width;

		play.function = Function::ChangeState;
		play.state = GameState::Gameplay;
		play.rec.width = 5.0f * screenWidthScalar;
		play.rec.height = 4.0f * screenHeightScalar;
		play.rec.x = buttonsX;
		play.rec.y = (static_cast<float>(screenHeight) / 3.0f) * 2;
		play.text = "PLAY";
	}
}

namespace game_over
{
	void InitializeButtons()
	{
		return_.function = Function::ChangeState;
		return_.state = GameState::MainMenu;
		return_.rec.width = 9.0f * screenWidthScalar;
		return_.rec.height = 3.0f * screenHeightScalar;
		return_.rec.x = 1.0f * screenWidthScalar;
		return_.rec.y = 1.0f * screenHeightScalar;
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

void CheckButtonPressing(Button button)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		PlaySound(buttonSFX);

		switch (button.function)
		{
		case Function::ChangeState:
			currentGameState = button.state;
			break;
		case Function::ExitGame:
			gameShouldClose = true;
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
		DrawRectangle(static_cast<int>(button.rec.x - 0.5f * screenWidthScalar), static_cast<int>(button.rec.y - 0.5f * screenHeightScalar), static_cast<int>(button.rec.width), static_cast<int>(button.rec.height), RAYWHITE);
		DrawText(button.text, static_cast<int>(button.rec.x), static_cast<int>(button.rec.y), 20, BLACK);
	}
	else
		DrawText(button.text, static_cast<int>(button.rec.x), static_cast<int>(button.rec.y), 20, RAYWHITE);
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
}