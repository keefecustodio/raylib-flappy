#include "Player.h"
#include <iostream>

int Player::player_score {0};

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
    if(IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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

bool Player::is_colliding_with_score_box(Rectangle self, Rectangle score_box) {
    return CheckCollisionRecs(self, score_box);
}

Rectangle Player::get_player_sprite() {
    return player_sprite;
}

void Player::increment_score() {
    player_score++;
}