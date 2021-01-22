#pragma once
#include <vector>;
/* Node of the tree */
class Node
{
public:
	Node() {
		playerMove = new int[2];
		computerMove = new int[2];
	}
	/* Getters */
	std::vector<Node*> get_children(); // Returns all possible next steps
	int* get_player_move(); // Returns player's move
	int* get_computer_move(); // Returns computer's move
	/* Setters */
	void set_computer_move(int, int); // Set computer's move
	void set_player_move(int, int); // Set player's move
	/* Other */
	void add_child(int player_move_x, int player_move_y, int computer_move_x, int computer_move_y); // Add possible next step

	~Node() {
		delete []playerMove;
		delete []computerMove;
	}
	friend class Tree;
private:
	std::vector<Node*> children; // Next possible steps after current one
	int* playerMove; // Player's move
	int* computerMove; // Computer move depending on player's move
};

