#include "raylib.h"
#include "raymath.h"

int main()
{
    const float windowWidth{384};
    const float windowHeight{384};

    InitWindow(windowWidth, windowHeight, "Battle Me");

    // load background
    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    const float mapScale{4.0f};
    Vector2 mapPos{-500.f, -500.f};
    float speed{4.0f};

    Texture2D knight = LoadTexture("characters/blobby_idle_spritesheet.png");
    // The position on the screen for the characters' upper left corner
    Vector2 knightPos{
        // half the window with - half the width of the knight so its' centered
        (float)windowWidth/2.0f - mapScale * (0.5f * (float)knight.width/7.0f),
        (float)windowHeight/2.0f - mapScale * (0.5f * (float)knight.height)
    };

    // value of 1 : facing right, value of -1 facing left
    float rightLeft{1.f};
    // animation variables
    float runningTime{};
    // current animation frame from the spritesheet
    int frame{};
    const int maxFrames{7};
    // animation will update 12f per second
    const float updateTime{1.f/12.f};

    // call character

    // call props

    // call enemys

    // set enemy target

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // initialize with 0
        Vector2 direction{};
        // if pressing A, direction is pointing to the left with a magnitude of 1
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        // if pressing D, pointing to the right with a magnitude of 1
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        // use direction to move the map
        // check direction: if direction is zero, we don't move
        if (Vector2Length(direction) != 0)
        {
            // can include diagonal direction
            // set mapPos = mapPos - direction
            // Vector2Scale gets the normalized movement direction, scales it by speed and the result is subtracted from the mapPos
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
            // check direction.x, if negative - the character is moving towards the left : positive, right
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        }

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.f, WHITE);

        // update animation frame
        // GetFrameTime or deltaTime
        runningTime += GetFrameTime();
        // increase frame count per second
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        }

        // draw the character
        // the location on the spritesheet that we want to use
        // multiply rightLeft to scale width to flips it's value, changing its' direction
        Rectangle source{frame * (float)knight.width/7.f, 0.f, rightLeft * (float)knight.width/7.f, (float)knight.height};
        // the location we want to draw the character in the window
        Rectangle dest{knightPos.x, knightPos.y, mapScale * (float)knight.width/7.0f, mapScale * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        // draw the props

        // character health status check

        // character.tick(GetFrameTime());

        // check map bounds to undo movement

        // check prop collisions

        // get enemy positions

        // attack check

        EndDrawing();
    }

    CloseWindow();
}