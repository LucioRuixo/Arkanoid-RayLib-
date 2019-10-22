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
	DrawText("ARKANOID!", static_cast<int>(buttons::buttonsX), static_cast<int>(/*screenHeight / 3*/screenHeight - buttons::exit.rec.y), 30, RAYWHITE);
	DrawText("Controls:  <- & ->  or  A & D to move / SPACE to release the ball", static_cast<int>(buttons::buttonsX), static_cast<int>(/*screenHeight / 3 + 15 * screenHeightScalar*/screenHeight - buttons::credits.rec.y), 20, RAYWHITE);
	DrawText("Break all the blocks to win", static_cast<int>(buttons::buttonsX), static_cast<int>(/*screenHeight / 3 + 20 * screenHeightScalar*/screenHeight - buttons::play.rec.y), 20, RAYWHITE);
	DrawText("M: Mute / Unmute music", static_cast<int>((screenWidth / 5) * 4), static_cast<int>((screenHeight / 8) * 5.75f), 20, RAYWHITE);
	DrawText("P: Close game", static_cast<int>((screenWidth / 5) * 4), static_cast<int>((screenHeight / 8) * 6), 20, RAYWHITE);

	buttons::DrawButton(buttons::credits);
	buttons::DrawButton(buttons::exit);
	buttons::DrawButton(buttons::fullScreen);
	buttons::DrawButton(buttons::play);
}
}
}