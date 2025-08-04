#include "Pipe.h"
#include <iostream>

void Pipe::draw_pipe() {
    DrawRectangleLinesEx(
        top_pipe_sprite,
        1.0f,
        WHITE
    );

    DrawRectangleLinesEx(
        bottom_pipe_sprite,
        1.0f,
        WHITE
    );

    // std::cout << "pipe drawn" << std::endl;
}

void Pipe::move_pipe() {
    top_pipe_sprite.x -= pipe_speed * GetFrameTime();
    bottom_pipe_sprite.x -= pipe_speed * GetFrameTime();

    // std::cout << top_pipe_sprite.x << std::endl;
}

float Pipe::get_pipe_position() {
    return top_pipe_sprite.x;
}

Pipe::Pipe(float random_number) : pipe_gap_position(random_number) {

}