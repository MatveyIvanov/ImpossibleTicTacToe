#include "Field.h"


/* Draw methods */

void Field::draw_field(RenderWindow& window) {
	VertexArray field(Lines, 16);
	field[0].position = fieldStart;
	field[1].position = Vector2f(this->fieldStart.x + this->cellSize * 3, this->fieldStart.y);
	field[2].position = Vector2f(this->fieldStart.x + this->cellSize * 3, this->fieldStart.y);
	field[3].position = Vector2f(this->fieldStart.x + this->cellSize * 3, this->fieldStart.y + this->cellSize * 3);
	field[4].position = Vector2f(this->fieldStart.x + this->cellSize * 3, this->fieldStart.y + this->cellSize * 3);
	field[5].position = Vector2f(this->fieldStart.x, this->fieldStart.y + this->cellSize * 3);
	field[6].position = Vector2f(this->fieldStart.x, this->fieldStart.y + this->cellSize * 3);
	field[7].position = this->fieldStart;
	field[8].position = Vector2f(this->fieldStart.x + this->cellSize, this->fieldStart.y);
	field[9].position = Vector2f(this->fieldStart.x + this->cellSize, this->fieldStart.y + this->cellSize * 3);
	field[10].position = Vector2f(this->fieldStart.x + this->cellSize * 2, this->fieldStart.y);
	field[11].position = Vector2f(this->fieldStart.x + this->cellSize * 2, this->fieldStart.y + this->cellSize * 3);
	field[12].position = Vector2f(this->fieldStart.x, this->fieldStart.y + this->cellSize);
	field[13].position = Vector2f(this->fieldStart.x + this->cellSize * 3, this->fieldStart.y + this->cellSize);
	field[14].position = Vector2f(this->fieldStart.x, this->fieldStart.y + this->cellSize * 2);
	field[15].position = Vector2f(this->fieldStart.x + this->cellSize * 3, this->fieldStart.y + this->cellSize * 2);
	window.draw(field);
}

void Field::draw_moves(RenderWindow& window) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			int* position = new int[2];
			position[0] = row;
			position[1] = column;
			if (field[row][column] == 1)
				draw_cross(window, position, Color::White);
			else if (field[row][column] == 2)
				draw_zero(window, position, Color::White);
			else if (field[row][column] == 3)
				draw_cross(window, position, Color::Red);
			else if (field[row][column] == 4)
				draw_zero(window, position, Color::Red);
		}
	}
}

void Field::draw_cross(RenderWindow& window, int* position, Color color) {
	VertexArray cross(Lines, 4);
	cross[0].position = Vector2f(this->fieldStart.x + this->cellSize * position[1] + 10, this->fieldStart.y + this->cellSize * position[0] + 10);
	cross[1].position = Vector2f(this->fieldStart.x + this->cellSize * (position[1] + 1) - 10, this->fieldStart.y + this->cellSize * (position[0] + 1) - 10);
	cross[2].position = Vector2f(this->fieldStart.x + this->cellSize * (position[1] + 1) - 10, this->fieldStart.y + this->cellSize * position[0] + 10);
	cross[3].position = Vector2f(this->fieldStart.x + this->cellSize * position[1] + 10, this->fieldStart.y + this->cellSize * (position[0] + 1) - 10);
	cross[0].color = color;
	cross[1].color = color;
	cross[2].color = color;
	cross[3].color = color;
	window.draw(cross);
}

void Field::draw_zero(RenderWindow& window, int* position, Color color) {
	CircleShape zero((this->cellSize - 10) / 2);
	zero.setPosition(this->fieldStart.x + this->cellSize * position[1] + 5, this->fieldStart.y + this->cellSize * position[0] + 5);
	zero.setFillColor(Color::Transparent);
	zero.setOutlineThickness((color == Color::White) ? 1 : 2);
	zero.setOutlineColor(color);
	window.draw(zero);
}

void Field::draw_restart_button(RenderWindow& window, Texture& restartImage) {
	this->restartButtonImage.setPosition(window.getSize().x - restartImage.getSize().x - 50, 50);
	this->restartButtonImage.setTexture(restartImage);

	window.draw(this->restartButtonImage);
}

void Field::draw_menu_button(RenderWindow& window, Texture& menuImage) {
	this->menuButtonImage.setPosition(50, 50);
	this->menuButtonImage.setTexture(menuImage);

	window.draw(this->menuButtonImage);
}

void Field::draw_winner(RenderWindow& window, Font& font) {
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::Blue);
	if (this->winner == "computer") {
		gameOverText.setString("YOU LOST!");
		gameOverText.setPosition(window.getSize().x / 12, window.getSize().y / 4);
	}
	else if (this->winner == "player") {
		gameOverText.setString("YOU WON!");
		gameOverText.setPosition(window.getSize().x / 12, window.getSize().y / 4);
	}
	else {
		gameOverText.setString("DRAW!");
		gameOverText.setPosition(window.getSize().x / 4, window.getSize().y / 4);
	}
	gameOverText.setCharacterSize(250);

	window.draw(gameOverText);
}


/* Move methods */

void Field::computer_move(RenderWindow& window, Computer& computer, Field& field, Menu& menu) {
	int* position = computer.move(field, menu);
	if (computer.get_suit() == "cross" && this->field[position[0]][position[1]] == 0) {
		this->field[position[0]][position[1]] = 1;
	}
	else if (this->field[position[0]][position[1]] == 0) {
		this->field[position[0]][position[1]] = 2;
	}
}


/* Getters */

Sprite Field::get_menu_button() {
	return this->menuButtonImage;
}

Sprite Field::get_restart_button() {
	return this->restartButtonImage;
}

Vector2f Field::get_field_start() {
	return this->fieldStart;
}

int Field::get_cell_size() {
	return this->cellSize;
}

int** Field::get_field() {
	return this->field;
}

int* Field::get_player_last_move() {
	return this->playerLastMove;
}

bool Field::get_game_over() {
	return this->gameOver;
}

std::string Field::get_winner() {
	return this->winner;
}

std::string Field::get_current_move() {
	return this->currentMove;
}


/* Setters */

void Field::set_current_move(std::string move) {
	this->currentMove = move;
}

void Field::set_player_last_move(int* position) {
	this->playerLastMove = position;
}

void Field::set_game_over(bool game_over) {
	this->gameOver = game_over;
}

void Field::set_winner(std::string s) {
	this->winner = s;
}


/* Other */

int* Field::spot_cell(Vector2i mousePos) {
	int* position = new int[2];
	position[0] = (mousePos.y - this->fieldStart.y) / this->cellSize;
	position[1] = (mousePos.x - this->fieldStart.x) / this->cellSize;
	return position;
}

bool Field::cell_is_available(int* position) {
	if (this->field[position[0]][position[1]] == 0)
		return true;
	else 
		return false;
}

void Field::reset(Computer& computer, Player& player) {
	for (int row = 0; row < 3; row++)
		for (int column = 0; column < 3; column++)
			this->field[row][column] = 0;
	this->gameOver = false;
	this->winner = "";
	if (this->get_current_move() == "player") {
		player.set_suit("cross");
		computer.set_suit("zero");
	}
	else {
		player.set_suit("zero");
		computer.set_suit("cross");
	}
	computer.get_tree()->set_current_node(computer.get_tree()->get_root());
	computer.set_current_move(1);
}