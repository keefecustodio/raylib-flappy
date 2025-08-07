#include <iostream>
#include <raylib.h>
#include <vector>
#include <ctime>
#include <thread>
#include <string>
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>
#include <memory>
#include <random>
#include "classes/Player/Player.h"
#include "classes/Pipe/Pipe.h"

const int screenWidth = 1600;
const int screenHeight = 900;

int min_val = -300;
int max_val = 300;

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(min_val, max_val); // define the range

// Function Prototypes
void draw_center_lines();
void draw_cursor_lines();
void periodicTask(std::vector<std::unique_ptr<Pipe>> &pipes);
void repeatingTimer(std::function<void()> task, std::chrono::milliseconds interval);

int main() {
    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    std::vector<std::unique_ptr<Pipe>> pipes;

    Player flappy;
    flappy.set_init_player_position(200, screenHeight/2);

    auto startTime = std::chrono::steady_clock::now();
    bool timerRunning = true;

    SetTargetFPS(144);

    std::chrono::milliseconds interval(1500);
    std::thread timerThread(repeatingTimer, std::bind(periodicTask, std::ref(pipes)), interval);
    timerThread.detach();

    // Main Game Loop
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

            flappy.spawn_player();

            for(auto& single_pipe: pipes) {
                single_pipe->draw_pipe();
                single_pipe->move_pipe();
            }


            Rectangle top_pipe_hitbox;
            
            Rectangle bottom_pipe_hitbox;

            Rectangle score_hitbox;

            if(!pipes.empty()) {
                score_hitbox = pipes.front()->get_score_hitbox();
                score_hitbox.x += 9.5f;

                top_pipe_hitbox = pipes.front()->get_top_pipe_sprite();
                top_pipe_hitbox.height -= 5.0f;
                top_pipe_hitbox.width -= 15.0f;
                top_pipe_hitbox.x += 9.5f;

                

                bottom_pipe_hitbox = pipes.front()->get_bottom_pipe_sprite();
                bottom_pipe_hitbox.height -= 5.0f;
                bottom_pipe_hitbox.width -= 15.0f;
                bottom_pipe_hitbox.x += 9.5f;
                // bottom_pipe_hitbox.y += 200.0f;
                bottom_pipe_hitbox.y += 5.0f;

                // draw collision boxes for the pipes.
                DrawRectangleLinesEx(
                    top_pipe_hitbox,
                    1.0f,
                    RED
                );

                DrawRectangleLinesEx(
                    bottom_pipe_hitbox,
                    1.0f,
                    RED
                );

                // draw collision boxe for the score hitbox
                // currently does not work :(
                DrawRectangleLinesEx(
                    score_hitbox,
                    1.0f,
                    GREEN
                );
            }
            
            if(!pipes.empty() && flappy.is_colliding_with_pipes(flappy.get_player_sprite(), top_pipe_hitbox, bottom_pipe_hitbox)) {
                // std::this_thread::sleep_for(std::chrono::seconds(100)); 
                std::cout << "COLLIDED" << std::endl;
                // EndDrawing();
                // CloseWindow();
                // return 0;
            }
            
            // despawn pipe when out of frame
            if(!pipes.empty() && pipes.front()->get_pipe_position() < -100.0f) {
                pipes.erase(pipes.begin());
            }

        EndDrawing();
    }



    CloseWindow();

    return 0;
}



// Function Definitions

// Function to be executed by the timer
void periodicTask(std::vector<std::unique_ptr<Pipe>> &pipes) {
    float random_num = static_cast<float>(distr(gen));
    pipes.push_back(std::make_unique<Pipe>(random_num));
    std::cout << "Periodic task executed!" << std::endl;
}

// Function to run in a separate thread for the timer
void repeatingTimer(std::function<void()> task, std::chrono::milliseconds interval) {
    while (true) {
        std::this_thread::sleep_for(interval);
        task();
    }
}

// to help with positioning / centering of objects
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


// for fun
void draw_cursor_lines() {
    DrawLineEx({0, static_cast<float>(GetMouseY())}, {screenWidth, static_cast<float>(GetMouseY())}, 1.0f, WHITE);
    DrawLineEx({static_cast<float>(GetMouseX()), 0}, {static_cast<float>(GetMouseX()), screenHeight}, 1.0f, WHITE);
}

// todo
// - edit pipe rectangles to be a little more forgiving for player collision DONE
// - add ability to pause
// - add a score
// - kill the player on collision