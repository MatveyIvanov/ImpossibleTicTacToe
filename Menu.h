#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Menu
{
public:
	Menu(): gameStarted(false), difficulty("impossible") {}
	/* Draw methods */
	void draw_menu(RenderWindow&, Texture&, Texture&, Font&); // Draw menu
	void draw_start_game_button(RenderWindow&, Texture&, Font&); // Draw start game button
	void draw_difficulty_change_button(RenderWindow&, Texture&, Font&); // Draw difficulty change button
	void draw_close_button(RenderWindow&, Texture&); // Draw close game button
	/* Getters */
	Sprite get_start_button(); // Returns start game button
	Sprite get_difficulty_button(); // Returns choosing difficulty button
	Sprite get_close_button(); // Returns close game button
	std::string get_difficulty(); // Returns difficulty of the game
	/* Other */
	void change_difficulty(); // Change current difficulty
	bool game_is_started(); // Returns true if game is started
	void start_game(bool); // Start game action
private:
	bool gameStarted; // True if game is started
	std::string difficulty; // normal/impossible
	Sprite startGameButtonImage; // Start game button
	Sprite difficultyButtonImage; // Choose difficulty button
	Sprite closeButtonImage; // Close game button
};

