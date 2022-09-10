#include "raylib.h"

int main()
{
    // window dimensions
    const int winWidth{512};
    const int winHeight{380};
    // initialize window
    InitWindow(winWidth, winHeight, "Dapper Dasher");

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity{1'000};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = winWidth/2 - scarfyRec.width/2;
    scarfyPos.y = winHeight -scarfyRec.height;

    int velocity{0};

    // is the rectangle in the air?
    bool isInAir{false};
    // jump velocity (pixels/sec)
    const int jumpVel{-600};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // delta time (time since last frame)
        const float dT{GetFrameTime()};

        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        // Game logic starts here:

        // perform ground check
        if (scarfyPos.y >= winHeight - scarfyRec.height)
        {
            // scarfy is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // scarfy is in the air
            velocity += gravity * dT;
            isInAir = true;
        }

        // jump check
        if (IsKeyDown(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        scarfyPos.y += velocity * dT;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        

        // Game logic ends here:
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}