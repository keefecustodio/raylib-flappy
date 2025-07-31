#include "Player.h"

Vector2 Player::get_player_position() {
    return player_position;
}

void Player::set_player_position(float x, float y) {
    player_position.x = x;
    player_position.y = y;
}

void Player::draw_player() {
    DrawRectanglePro(
        player_sprite, 
        { player_sprite.width / 2.0f, player_sprite.height / 2.0f }, 
        0, 
        WHITE
    );
}