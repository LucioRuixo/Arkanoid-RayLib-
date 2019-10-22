#include "credits_screen.h"

#include "Elements/buttons.h"

namespace game
{
namespace credits_screen
{
int creditsX;
int creditsY;
int lineSpace;

void Initialize()
{
	creditsX = static_cast<int>(5 * screenWidthScalar);
	creditsY = static_cast<int>(10 * screenHeightScalar);
	lineSpace = static_cast<int>(5 * screenHeightScalar);
}

void Update()
{
	buttons::UpdateButton(buttons::return_);
}

void Draw()
{
	buttons::DrawButton(buttons::return_);

	DrawText("CREDITS:", creditsX, creditsY, 30, RAYWHITE);
	DrawText("AUTOR AND PROGRAMMER", creditsX, static_cast<int>(creditsY + lineSpace * 2.5), 20, RAYWHITE);
	DrawText("Lucio Ruixo", creditsX, creditsY + static_cast<int>(lineSpace * 3.5f), 20, RAYWHITE);
	DrawText("TOOLS USED", creditsX, creditsY + lineSpace * 5, 20, RAYWHITE);
	DrawText("Library: RayLib 2.5.0 Win32 ... https://www.raylib.com/", creditsX, creditsY + lineSpace * 6, 20, RAYWHITE);
	DrawText("IDE: Microsoft Visual Studio 2017 ... https://visualstudio.microsoft.com/", creditsX, static_cast<int>(creditsY + lineSpace * 6.5f), 20, RAYWHITE);
	DrawText("Audio edition: Audacity 2.3.2 ... https://www.audacityteam.org/", creditsX, creditsY + lineSpace * 7, 20, RAYWHITE);
	DrawText("SOUND EFFECTS", creditsX, static_cast<int>(creditsY + lineSpace * 8.5f), 20, RAYWHITE);
	DrawText("ZapSplat - 'Multimedia plastic style button click 3' ... https://www.zapsplat.com/", creditsX, static_cast<int>(creditsY + lineSpace * 9.5f), 20, RAYWHITE);
	DrawText("Exposed Tv - 'Pong Sound Effect' ... https://www.youtube.com/watch?v=IExAq3GBRvI", creditsX, creditsY + lineSpace * 10, 20, RAYWHITE);
	DrawText("MUSIC", creditsX, static_cast<int>(creditsY + lineSpace * 11.5f), 20, RAYWHITE);
	DrawText("Tyler River - 'Solemn Mood Chiptune' ... https://youtu.be/7M6Y7ROT-u8?t=94", creditsX, static_cast<int>(creditsY + lineSpace * 12.5f), 20, RAYWHITE);
}
}
}