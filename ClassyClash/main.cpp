#include "raylib.h"
#include "raymath.h"
#include "Character.h"

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

    Character knight;
    knight.setScreenPos(winDims[0], winDims[1]);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        knight.tick(GetFrameTime());

        // game logic


        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}