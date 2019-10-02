#include "game.h"

const int SCREEN_WIDTH = 405; //9
const int SCREEN_HEIGHT = 720; //16
const int PLADDLE_SPEED = 5;
const int BALL_SPEED = 5;

enum GameState
{
	MainMenu,
	SelectionMenu,
	Playing,
	GameOver
};

struct Player
{
	Rectangle rec;
	Vector2 position;

	int lives = 3;
	int speed = PLAYER_SPEED;
};

struct Ball
{
	Vector2 position;
	Vector2 direction;

	int speed = BALL_SPEED;
	int radius;
};

struct Level
{
	int layout[8][10];

	int num;
};

struct Layouts
{
	int l1[8][10];
	int l2[8][10];
	int l3[8][10];
	int l4[8][10];
	int l5[8][10];
	int l6[8][10];
	int l7[8][10];
	int l8[8][10];
	int l9[8][10];
	int l10[8][10];
};

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

	Vector2 cursor;

	GameState currentGameState = GameState::MainMenu;

	Ball ball;
	ball.position = { (float)screenWidth / 2, (float)screenHeight / 2 };

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		while (!WindowShouldClose() && currentGameState == GameState::MainMenu)
		{
			cursor = GetMousePosition();

			DrawText("ARKANOID!", screenWidth / 2 - 175, screenHeight / 2 - 70, 20, RAYWHITE);

			if ((cursor.x > screenWidth / 2 - 175 && cursor.x < screenWidth / 2 - 175 + 50)
				&&
				(cursor.y > screenHeight / 2 - 70 && cursor.y < screenHeight / 2 - 70 + 20))
			{
				DrawRectangle(screenWidth / 2 - 175, screenHeight / 2 - 70, 50, 20, RAYWHITE);
				DrawText("Jugador vs. Jugador", (int)screenWidth / 2 - 175 + 5, (int)screenHeight / 2 - 70 + 5, 20, BLACK);
			}
			else
				DrawText("Jugador vs. Jugador", (int)screenWidth / 2 - 175 + 5, (int)screenHeight / 2 - 70 + 5, 20, RAYWHITE);
			if (((cursor.x > screenWidth / 2 - 175 && cursor.x < screenWidth / 2 - 175 + 50)
				&&
				(cursor.y > screenHeight / 2 - 70 && cursor.y < screenHeight / 2 - 70 + 20)) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				currentGameState = GameState::Playing;
			}

			EndDrawing();
			ClearBackground(BLACK);
		}

		while (!WindowShouldClose() && currentGameState == GameState::Playing)
		{
			// Update
			//----------------------------------------------------------------------------------
			if (IsKeyDown(KEY_RIGHT)) ball.position.x += 2.0f;
			if (IsKeyDown(KEY_LEFT)) ball.position.x -= 2.0f;
			if (IsKeyDown(KEY_UP)) ball.position.y -= 2.0f;
			if (IsKeyDown(KEY_DOWN)) ball.position.y += 2.0f;
			//----------------------------------------------------------------------------------

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

			DrawCircleV(ball.position, 50, MAROON);

			EndDrawing();
			//----------------------------------------------------------------------------------
		}
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}