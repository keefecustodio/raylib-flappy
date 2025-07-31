#include <iostream>
#include <raylib.h>
#include "classes/Player/Player.h"




const int screenWidth = 1600;
const int screenHeight = 900;

void draw_center_lines();

int main() {


    std::cout << "hello world" << std::endl;
    
    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    Player flappy;
    flappy.set_player_position(200, screenHeight/2);

    std::cout << flappy.get_player_position().x << std::endl;
    std::cout << flappy.get_player_position().y << std::endl;

    

    // main game loop
    while(!WindowShouldClose()) {
        BeginDrawing();


        // DrawCircle(screenWidth/2, screenHeight/2, 100.0f, WHITE);
        draw_center_lines();

        flappy.draw_player();

        
        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

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