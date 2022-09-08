#include "raylib.h"

int main()
{
    int width;
    width = 350;
    InitWindow(width, 200, "JC Window");

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);
        DrawCircle(175, 100, 25, BLUE);
        EndDrawing();
    }
}