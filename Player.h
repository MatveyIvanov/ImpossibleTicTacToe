#pragma once
#include <string>
#include "Field.h"

class Field;


class Player
{
public:
	Player(): suit("zero") {}
	/* Getters */
	std::string get_suit(); // Return suit of the player
	/* Setters */
	void set_suit(std::string); // Set suit of the player
	/* Move */
	void move(Field&, int*); // Player move
private:
	std::string suit; // cross/zero
};

