#include "raylib.h"
#include "raymath.h"

int main()
{
    int winDims[2];
    winDims[0] = 384;
    winDims[1] = 384;

    // initialize window
    InitWindow(winDims[0], winDims[1], "Classy Clash");

    // load background
    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};

    float speed{4.0};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{ };
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            // set mapPos = mapPos - direction
            
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // draw the background
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // game logic

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}