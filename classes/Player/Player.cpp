#include "Player.h"
#include <iostream>

Vector2 Player::get_player_position() {
    return player_position;
}

void Player::set_init_player_position(float x, float y) {
    player_position.x = x;
    player_position.y = y;
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
}

void Player::controls() {
    if(IsKeyPressed(KEY_SPACE)) {
        player_velocity.y = -player_jump_force;
        
    }
}

void Player::spawn_player() {
    Player::draw_player();
    Player::apply_gravity();
    Player::controls();
}

bool Player::is_colliding_with_pipes(Rectangle self, Rectangle top_pipe, Rectangle bottom_pipe) {
    return (CheckCollisionRecs(self, top_pipe) || CheckCollisionRecs(self, bottom_pipe));
}

Rectangle Player::get_player_sprite() {
    return player_sprite;
}