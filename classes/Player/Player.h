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

        Vector2 player_velocity {
            0.0f, // x
            100.0f // y
        };

        float player_jump_force { 700.0f };
        
        float player_gravity { 1800.0f };

        float player_max_velocity { 1800.0f };

    public:
        Vector2 get_player_position();
        void set_init_player_position(float x, float y);
        void draw_player();
        void apply_gravity();
        // void apply_gravity_no_velocity();

        void controls();
};


#endif