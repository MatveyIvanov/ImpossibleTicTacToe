#include "Menu.h"

const int BUTTON_SIZE[2] = { 680, 229 };


/* Draw methods */

void Menu::draw_menu(RenderWindow& window, Texture& defaultImage, Texture& closeImage, Font& font) {
	this->draw_difficulty_change_button(window, defaultImage, font);
	this->draw_start_game_button(window, defaultImage, font);
	this->draw_close_button(window, closeImage);
}

void Menu::draw_start_game_button(RenderWindow& window, Texture& defaultImage, Font& font) {
	startGameButtonImage.setPosition((window.getSize().x - defaultImage.getSize().x) / 2, window.getSize().y / 7.5);
	startGameButtonImage.setTexture(defaultImage);
	Text startGame;
	startGame.setFont(font);
	startGame.setFillColor(Color::Blue);
	startGame.setString("START");
	startGame.setPosition(startGameButtonImage.getPosition().x + 150, startGameButtonImage.getPosition().y + 50);
	startGame.setCharacterSize(100);

	window.draw(startGameButtonImage);
	window.draw(startGame);
}

void Menu::draw_difficulty_change_button(RenderWindow& window, Texture& defaultImage, Font& font) {
	difficultyButtonImage.setPosition((window.getSize().x - defaultImage.getSize().x / 2) / 2, window.getSize().y / 1.75);
	difficultyButtonImage.setTexture(defaultImage);
	difficultyButtonImage.setScale(0.5, 0.5);
	Text difficulty;
	difficulty.setFont(font);
	difficulty.setFillColor(Color::Blue);
	difficulty.setString(this->difficulty);
	if (this->difficulty == "normal")
		difficulty.setPosition(difficultyButtonImage.getPosition().x + 75, difficultyButtonImage.getPosition().y + 25);
	else
		difficulty.setPosition(difficultyButtonImage.getPosition().x + 30, difficultyButtonImage.getPosition().y + 25);
	difficulty.setCharacterSize(50);

	window.draw(difficultyButtonImage);
	window.draw(difficulty);
}

void Menu::draw_close_button(RenderWindow& window, Texture& closeImage) {
	closeButtonImage.setPosition(1700, 50);
	closeButtonImage.setTexture(closeImage);
	closeButtonImage.setScale(0.25, 0.25);

	window.draw(closeButtonImage);
}


/* Getters */

Sprite Menu::get_start_button() {
	return this->startGameButtonImage;
}

Sprite Menu::get_difficulty_button() {
	return this->difficultyButtonImage;
}

Sprite Menu::get_close_button() {
	return this->closeButtonImage;
}

std::string Menu::get_difficulty() {
	return this->difficulty;
}


/* Other */

void Menu::change_difficulty() {
	if (this->difficulty == "normal")
		this->difficulty = "impossible";
	else
		this->difficulty = "normal";
}

bool Menu::game_is_started() {
	return this->gameStarted;
}

void Menu::start_game(bool startGame) {
	this->gameStarted = startGame;
}