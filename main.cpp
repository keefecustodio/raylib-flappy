#include <iostream>
#include <raylib.h>
#include "classes/Player/Player.h"
#include "classes/Pipe/Pipe.h"




const int screenWidth = 1600;
const int screenHeight = 900;

// Function Prototypes
void draw_center_lines();
void draw_cursor_lines();

int main() {

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    Player flappy;
    flappy.set_init_player_position(200, screenHeight/2);


    Pipe pipe;




    SetTargetFPS(144);

    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

            draw_center_lines();

            flappy.spawn_player();
            pipe.draw_pipe();


            


        EndDrawing();
    }



    CloseWindow();

    return 0;
}





// Function Definitions
void draw_center_lines() {
    DrawLine(
        0, // x start pos
        screenHeight/2, // y start pos
        screenWidth, //x end pos
        screenHeight/2, // y end pos
        WHITE
    );

    DrawLine(
        screenWidth/2, // x start pos
        0, // y start pos
        screenWidth/2, //x end pos
        screenHeight, // y end pos
        WHITE
    );
}

void draw_cursor_lines() {
    DrawLineEx({0, static_cast<float>(GetMouseY())}, {screenWidth, static_cast<float>(GetMouseY())}, 1.0f, WHITE);
    DrawLineEx({static_cast<float>(GetMouseX()), 0}, {static_cast<float>(GetMouseX()), screenHeight}, 1.0f, WHITE);
}