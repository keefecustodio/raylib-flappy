#include <iostream>
#include <raylib.h>

int main() {


    const int screenWidth = 1600;
    const int screenHeight = 900; 


    std::cout << "hello world" << std::endl;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    while(!WindowShouldClose()) {
        BeginDrawing();


        DrawCircle(screenWidth/2, screenHeight/2, 100.0f, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}