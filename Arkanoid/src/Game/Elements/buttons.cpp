#include "buttons.h"

#include "game.h"

namespace game
{
Button continue_;
Button exit;
Button fullScreen_;
Button pause;
Button play;
Button return_;

void GenerateButton(Button button)
{
	if ((cursor.x > button.rec.x && cursor.x < button.rec.x + button.rec.width)
		&&
		(cursor.y > button.rec.y && cursor.y < button.rec.y + button.rec.height))
	{
		DrawRectangle(static_cast<int>(button.rec.x), static_cast<int>(button.rec.y), static_cast<int>(button.rec.width), static_cast<int>(button.rec.height), RAYWHITE);
		DrawText(button.text, static_cast<int>(button.rec.x + 5), static_cast<int>(button.rec.y + 5), 20, BLACK);
	}
	else
		DrawText(button.text, static_cast<int>(button.rec.x + 5), static_cast<int>(button.rec.y + 5), 20, RAYWHITE);
	if (((cursor.x > button.rec.x && cursor.x < button.rec.x + button.rec.width)
		&&
		(cursor.y > button.rec.y && cursor.y < button.rec.y + button.rec.height)) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		switch (button.function)
		{
		case Function::ChangeState:
			currentGameState = button.state;
			break;
		case Function::ExitGame:
			CloseWindow();
			break;
		case Function::Pause:
			//pauseActive ? pauseActive = false : pauseActive = true;
			break;
		case Function::ActivateFullscreen:
			ToggleFullscreen();
			break;
		}
	}
}

namespace main_menu
{
void InitializeButtons(Button &exit, Button &fullScreen_, Button &play)
{
	exit.function = Function::ExitGame;
	exit.rec.width = 60;
	exit.rec.height = 30;
	exit.rec.x = SCREEN_WIDTH / 2 - 20;
	exit.rec.y = SCREEN_HEIGHT / 2 + 115;
	exit.text = "Exit";

	fullScreen_.function = Function::ActivateFullscreen;
	fullScreen_.rec.width = 190;
	fullScreen_.rec.height = 30;
	fullScreen_.rec.x = SCREEN_WIDTH - fullScreen_.rec.width - 10;
	fullScreen_.rec.y = 10;
	fullScreen_.text = "Fullscreen";

	play.function = Function::ChangeState;
	play.state = GameState::Gameplay;
	play.rec.width = 80;
	play.rec.height = 30;
	play.rec.x = SCREEN_WIDTH / 2 - 35;
	play.rec.y = SCREEN_HEIGHT / 2 + 45;
	play.text = "PLAY";
}
}

namespace gameplay
{
void InitializeButtons(Button &continue_, Button &pause, Button &return_)
{
	continue_.function = Function::Pause;
	continue_.rec.width = 110;
	continue_.rec.height = 30;
	continue_.rec.x = SCREEN_WIDTH / 2 - continue_.rec.width / 2;
	//continue_.rec.y = SCREEN_HEIGHT / 2 - continue_.rec.height / 2 - ((pauseMenu.rec.height - continue_.rec.height * 3) / 4 + continue_.rec.height);
	continue_.text = "Continuar";

	pause.function = Function::Pause;
	pause.rec.width = 95;
	pause.rec.height = 30;
	pause.rec.x = 10;
	pause.rec.y = 10;
	pause.text = "|| Pausa";

	return_.function = Function::ChangeState;
	return_.state = GameState::MainMenu;
	return_.rec.width = 95;
	return_.rec.height = 30;
	return_.rec.x = 10;
	return_.rec.y = 10;
	return_.text = "< Return";
}
}

namespace game_over
{
	void InitButtons(Button return_)
	{
		return_.function = Function::ChangeState;
		return_.state = GameState::MainMenu;
		return_.rec.width = 95;
		return_.rec.height = 30;
		return_.rec.x = 10;
		return_.rec.y = 10;
		return_.text = "< Return";
	}
}
}