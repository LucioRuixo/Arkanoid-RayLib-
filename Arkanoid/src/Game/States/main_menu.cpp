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
	DrawText("ARKANOID!", buttonsX, screenHeight / 3, 30, RAYWHITE);
	DrawText("Controles:  <- y ->  o  A y W", buttonsX, screenHeight / 2 - 15, 20, RAYWHITE);
	DrawText("Rompe todos los bloques para ganar.", buttonsX, screenHeight / 2 + 15, 20, RAYWHITE);

	DrawButton(exit);
	DrawButton(fullScreen_);
	DrawButton(play);
}
}
}