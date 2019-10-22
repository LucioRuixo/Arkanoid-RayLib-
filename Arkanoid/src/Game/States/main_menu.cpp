#include "main_menu.h"

#include "game.h"
#include "Elements/buttons.h"

namespace game
{
namespace main_menu
{
void Update()
{
	buttons::UpdateButton(buttons::credits);
	buttons::UpdateButton(buttons::exit);
	buttons::UpdateButton(buttons::fullScreen);
	buttons::UpdateButton(buttons::play);
}

void Draw()
{
	DrawText("ARKANOID!", static_cast<int>(buttons::buttonsX), static_cast<int>(screenHeight / 3), 30, RAYWHITE);
	DrawText("Controles:  <- y ->  o  A y D", static_cast<int>(buttons::buttonsX), static_cast<int>(screenHeight / 2 - 15), 20, RAYWHITE);
	DrawText("Rompe todos los bloques para ganar.", static_cast<int>(buttons::buttonsX), static_cast<int>(screenHeight / 2 + 15), 20, RAYWHITE);
	DrawText("M: Mute / Unmute music", static_cast<int>((screenWidth / 5) * 4), static_cast<int>((screenHeight / 8) * 7), 20, RAYWHITE);

	buttons::DrawButton(buttons::credits);
	buttons::DrawButton(buttons::exit);
	buttons::DrawButton(buttons::fullScreen);
	buttons::DrawButton(buttons::play);
}
}
}