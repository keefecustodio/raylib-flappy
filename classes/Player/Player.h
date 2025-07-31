#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>

class Player {
    private:
        Vector2 player_position {
            1600.0f / 2, // x
            900.0f / 2 // y
        };

        Rectangle player_sprite {
            player_position.x, // rect top-left corner position x
            player_position.y, // rect top-left corner position y
            50.0f, // width
            50.0f, // height
        };


    public:
        Vector2 get_player_position();
        void set_player_position(float x, float y);
        void draw_player();
};


#endif