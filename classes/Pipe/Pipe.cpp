#include "Pipe.h"


void Pipe::draw_pipe() {
    DrawRectangleLinesEx(
        pipe_sprite,
        1.0f,
        WHITE
    );
}