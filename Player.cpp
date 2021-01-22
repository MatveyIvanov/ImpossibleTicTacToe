#include "Player.h"


/* Getters */

std::string Player::get_suit() {
	return this->suit;
}


/* Setters */

void Player::set_suit(std::string s) {
	this->suit = s;
}


/* Move */

void Player::move(Field& field, int* position) {
	int** f = field.get_field();
	if (this->get_suit() == "cross") {
		f[position[0]][position[1]] = 1;
	}
	else {
		f[position[0]][position[1]] = 2;
	}
	
	field.set_player_last_move(position);
	bool gameOver = true;
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (f[row][column] == 0) {
				gameOver = false;
				break;
			}
		}
	}
	field.set_game_over(gameOver);
}