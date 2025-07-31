#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>

class Player {
    private:
        Vector2 player_position {
            200.0f, // x position
            900.0f / 2.0f // y position
        };

        Rectangle player_sprite {
            player_position.x,
            player_position.y,
            50.0f, // width
            50.0f, // height
        };
        
        float player_gravity { 200.0f };

    public:
        Vector2 get_player_position();
        void set_init_player_position(float x, float y);
        void draw_player();
        void apply_gravity();
};


#endif