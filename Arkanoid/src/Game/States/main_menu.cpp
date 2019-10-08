#include "main_menu.h"

#include "game.h"
#include "Elements/buttons.h"

namespace game
{
namespace main_menu
{
static void Update()
{
	cursor = GetMousePosition();

	GenerateButton(fullScreen_);
	GenerateButton(play);
	GenerateButton(exit);
}

static void Draw()
{
	DrawText("ARKANOID!", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2 - 50, 20, RAYWHITE);
	DrawText("Controles:  <- y ->  o  A y W", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, 20, RAYWHITE);
	DrawText("Rompe todos los bloques para ganar.", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2 + 50, 20, RAYWHITE);
}

void Execute()
{
	while (!WindowShouldClose() && currentGameState == GameState::MainMenu)
	{
		ClearBackground(BLACK);

		Update();

		Draw();

		EndDrawing();
	}
}
}
}