#include "raylib.h"

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "JC Window");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_r{25};

    // circle edges
    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int u_circle_y{circle_y - circle_r};
    int b_circle_y{circle_y + circle_r};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_w{50};
    int axe_h{50};

    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_w};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_h};

    int direction{10};

    bool axe_collision = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        
        if(axe_collision)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic begins here:
            
            // Update circle edges
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y + circle_r;

            // Update axe edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_w;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_h;

            // Update axe_collision
            axe_collision = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            DrawRectangle(axe_x, axe_y, axe_w, axe_h, RED);

            // move the axe
            axe_y += direction;
            if(axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

        }
        
        // Game logic ends.
        EndDrawing();
    }
}