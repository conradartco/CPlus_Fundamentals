#include "raylib.h"

int main()
{
    // window dimensions
    const int winWidth{512};
    const int winHeight{380};
    // initialize window
    InitWindow(winWidth, winHeight, "Dapper Dasher");

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity{1};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{winHeight - height};
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        // Game logic starts here:

        // perform ground check
        if (posY >= winHeight - height)
        {
            // rectangle is on the ground
            velocity = 0;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity;
        }

        // move rectangle
        if (IsKeyDown(KEY_SPACE))
        {
            velocity -= 10;
        }

        // update position
        posY += velocity;

        DrawRectangle(winWidth/2, posY, width, height, BLUE);
        

        // Game logic ends here:
        EndDrawing();
    }
    CloseWindow();
}