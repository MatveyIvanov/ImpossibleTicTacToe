#pragma once
#include <SFML/Graphics.hpp>
#include "Computer.h"
#include "Player.h"
#include "Menu.h"

using namespace sf;

class Computer;
class Player;

class Field
{
public:
	Field(RenderWindow& window)
	{
		cellSize = window.getSize().y / 4; 
		fieldStart.x = window.getSize().x / 2 - 1.5 * cellSize;
		fieldStart.y = window.getSize().y / 2 - 1.5 * cellSize;
		currentMove = "player";
		winner = "draw";
		field = new int* [3];
		playerLastMove = new int[2];
		gameOver = false;
		for (int row = 0; row < 3; row++)
			field[row] = new int[3];
		for (int row = 0; row < 3; row++)
			for (int column = 0; column < 3; column++)
				field[row][column] = 0;
	}
	/* Draw methods */
	void draw_field(RenderWindow&); // Draw game field
	void draw_moves(RenderWindow&); // Draw moves of player and computer
	void draw_cross(RenderWindow&, int*, Color); // Draw cross
	void draw_zero(RenderWindow&, int*, Color); // Draw zero
	void draw_restart_button(RenderWindow&, Texture&); // Draw restart button
	void draw_menu_button(RenderWindow&, Texture&); // Draw menu button
	void draw_winner(RenderWindow&, Font&); // Draw winner
	/*  Move method */
	void computer_move(RenderWindow&, Computer&, Field&, Menu&);
	/* Getters */
	Sprite get_menu_button(); // Return menu buton
	Sprite get_restart_button(); // Return restart button
	Vector2f get_field_start(); // Get start of the field
	int get_cell_size(); // Get cell size
	int** get_field(); // Get field array
	int* get_player_last_move(); // Get player last move
	bool get_game_over(); // Return true if game is over
	std::string get_winner(); // Get winner of the game
	std::string get_current_move(); // Get current move
	/* Setters */
	void set_current_move(std::string); // Set current move
	void set_player_last_move(int*); // Set player's last move
	void set_game_over(bool); // Set true if game is over
	void set_winner(std::string); // Set winner of the game
	/* Other */
	int* spot_cell(Vector2i); // Spot the cell that player clicked on
	bool cell_is_available(int*); // Return true if cell is available for choosing it
	void reset(Computer&, Player&); // Reset game field
	~Field()
	{
		for (int row = 0; row < 3; row++)
			delete[]field[row];
	}
private:
	int **field; // Game field 3x3
	Vector2f fieldStart; // Top left position of the field
	int cellSize; // Cell size
	Sprite menuButtonImage; // Go to menu button
	Sprite restartButtonImage; // Restart button
	std::string currentMove; // player/computer
	int* playerLastMove; // Player's last move
	bool gameOver; // True if game is over
	std::string winner; // player/draw/computer
};

