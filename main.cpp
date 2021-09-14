#include <cstdio>
#include "raylib.h"

int main()
{
    // Window dimensions
    int width{400};
    int height{500};

    // circle coordinates
    int circle_x{width/2};
    int circle_y{height/2};
    int circle_radius{10};

    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};


    // Axe coordinates
    int axe_x{200};
    int axe_y{0};
    int axe_length{50};

    // Axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    

    // Game properties
    bool run{true};
    SetTargetFPS(60);
    int Speed{5};
    int direction{10};
    bool collision_with_axe{false};


    InitWindow(width,height,"Title");

    while(run == true)
    
    {
        if (WindowShouldClose() == true)
            {
                run = false;
            }
        BeginDrawing();

        // Check if the axe has colided with the circle

        if (b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x)
            {
                collision_with_axe = true;
            }

        if (collision_with_axe == true)
            {
                run = false;
                DrawText("Game Over!", 400,200,20,RED);
            }

        else
        {

            // Game logic begins //

            // Update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;


            DrawCircle(circle_x,circle_y,circle_radius,BLACK);
            DrawRectangle(axe_x,axe_y,axe_length,axe_length,RED);

            axe_y += direction;

            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }
            
            if (IsKeyDown(KEY_D) && circle_x + circle_radius < width)
            {
                circle_x += Speed;

            }

            if (IsKeyDown(KEY_S) && circle_y + circle_radius < height)
            {
                circle_y += Speed;

            }

            if (IsKeyDown(KEY_W) && circle_y - circle_radius > 0)
            {
                circle_y -= Speed;

            }

            if (IsKeyDown(KEY_A) && circle_x - circle_radius > 0)
            {
                circle_x -= Speed;

            }

        }
        ClearBackground(WHITE);
        EndDrawing();

        
    }

}
