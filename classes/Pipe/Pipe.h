#ifndef PIPE_H
#define PIPE_H
#include <raylib.h>

class Pipe {
    private:
        float pipe_gap {100.0f};
        float pipe_gap_position {150.0f}; // min/max should be -/+ 300.0f
        float pipe_speed {300.0f};

        Rectangle top_pipe_sprite {
            GetScreenWidth() + 75.0f, // x position of top left corner
            0.0f, // y position of top left corner
            75.0f, // width
            (static_cast<float>(GetScreenHeight()) / 2.0f) - pipe_gap + pipe_gap_position // height
        };

        Rectangle bottom_pipe_sprite {
            GetScreenWidth() + 75.0f, // x position of top left corner
            (static_cast<float>(GetScreenHeight()) / 2.0f) + pipe_gap + pipe_gap_position, // y position of top left corner
            75.0f, // width
            (static_cast<float>(GetScreenHeight()) / 2.0f) - pipe_gap - pipe_gap_position, // height
        };

    public:
        void draw_pipe();
        void move_pipe();
        float get_pipe_position();
};


#endif