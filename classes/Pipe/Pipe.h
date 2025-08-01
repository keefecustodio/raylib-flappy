#ifndef PIPE_H
#define PIPE_H
#include <raylib.h>

class Pipe {
    private:
        Rectangle pipe_sprite {
            200.0f, // x position of top left corner
            900.0f / 2.0f, // y position of top left corner
            50.0f, // width
            50.0f, // height
        };

    public:
        void draw_pipe();
};


#endif