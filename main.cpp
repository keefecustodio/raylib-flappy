#include <iostream>
#include <raylib.h>
#include "classes/Player/Player.h"
#include "classes/Pipe/Pipe.h"
#include <vector>
#include <ctime>
#include <thread>
#include <string>


#include <functional>
#include <chrono>
#include <future>
#include <cstdio>




const int screenWidth = 1600;
const int screenHeight = 900;

// Function Prototypes
void draw_center_lines();
void draw_cursor_lines();
void periodicTask(std::vector<Pipe> &pipes);
void repeatingTimer(std::function<void()> task, std::chrono::milliseconds interval);


int main() {
    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    std::vector<Pipe> pipes;

    Player flappy;
    flappy.set_init_player_position(200, screenHeight/2);


    // Pipe pipe;

    // pipes.push_back(pipe);


    auto startTime = std::chrono::steady_clock::now();
    bool timerRunning = true;



    SetTargetFPS(144);

    std::chrono::milliseconds interval(1000);
    std::thread timerThread(repeatingTimer, std::bind(periodicTask, std::ref(pipes)), interval);
    timerThread.detach();

    // std::this_thread::sleep_for(std::chrono::seconds(10)); 


    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

            draw_center_lines();

            flappy.spawn_player();
            // pipe.draw_pipe();
            // pipe.move_pipe();

            // std::cout << pipes.size() << std::endl;

            for(auto& single_pipe: pipes) { // this isn't even drawing anything..?
                single_pipe.draw_pipe();
                single_pipe.move_pipe();
                std::cout << pipes.size() << std::endl;
            }


            // bool CheckCollisionRecs();
            


            


        EndDrawing();
    }



    CloseWindow();

    return 0;
}



// Function to be executed by the timer
void periodicTask(std::vector<Pipe> &pipes) {
    Pipe temp;
    pipes.push_back(temp);
    std::cout << "Periodic task executed!" << std::endl;
    std::cout << pipes.size() << std::endl;
}

// Function to run in a separate thread for the timer
void repeatingTimer(std::function<void()> task, std::chrono::milliseconds interval) {
    while (true) {
        std::this_thread::sleep_for(interval);
        task();
    }
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