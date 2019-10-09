#include "main_menu.h"

#include "game.h"
#include "Elements/buttons.h"

namespace game
{
namespace main_menu
{
void Update()
{
	UpdateButton(exit);
	UpdateButton(fullScreen_);
	UpdateButton(play);
}

void Draw()
{
	ClearBackground(BLACK);

	DrawText("ARKANOID!", screenWidth/ 3, screenHeight / 2 - 50, 20, RAYWHITE);
	DrawText("Controles:  <- y ->  o  A y W", screenWidth / 3, screenHeight / 2, 20, RAYWHITE);
	DrawText("Rompe todos los bloques para ganar.", screenWidth / 3, screenHeight / 2 + 50, 20, RAYWHITE);

	DrawButton(exit);
	DrawButton(fullScreen_);
	DrawButton(play);
}
}
}