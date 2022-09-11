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

    // load character
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)winDims[0]/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        (float)winDims[1]/2.0f - 4.0f * (0.6f * (float)knight.height)
    };
    

    // 1: facing right, -1 : facing left
    float rightLeft{1.f};
    // animation variablees
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};

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
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knight = knight_run;
        }
        else
        {
            knight = knight_idle;
        }

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        }

        // draw the character
        Rectangle source{frame * (float)knight.width/6.f, 0.f, rightLeft * (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        Vector2 origin{};
        DrawTexturePro(knight, source, dest, origin, 0.f, WHITE);

        // game logic

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}