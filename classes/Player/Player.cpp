#include "Player.h"
#include <iostream>

Vector2 Player::get_player_position() {
    return player_position;
}

void Player::set_init_player_position(float x, float y) {
    player_position.x = x;
    player_position.y = y;

    // std::cout << player_position.y << std::endl;
}

void Player::draw_player() {
    DrawRectanglePro(
        player_sprite, // rectangle
        {player_sprite.width / 2.0f, player_sprite.height / 2.0f }, // origin
        0, // rotation
        WHITE // color
    );
}

void Player::apply_gravity() {
    player_velocity.y += player_gravity * GetFrameTime();
    player_sprite.y += player_velocity.y * GetFrameTime();

    std::cout << player_velocity.y << std::endl;
}

void Player::controls() {
    if(IsKeyPressed(KEY_SPACE)) {
        player_velocity.y = -player_jump_force;
        
    }
}

// void Player::apply_gravity_no_velocity() {
//     player_sprite.y += player_gravity * GetFrameTime();
// }