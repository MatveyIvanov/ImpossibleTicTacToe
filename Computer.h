#pragma once
#include <string>
#include "Menu.h"
#include "Field.h"
#include "Tree.h"

class Field;

class Computer
{
public:
	Computer() {
		suit = "cross";
		difficult = "normal";
		currentMove = 1;
		strategy = "win";
		impossibleTreeZero = new Tree();
		this->create_impossible_tree_for_zero();
	}
	/* Getters */
	std::string get_suit();
	bool get_difficulty();
	std::string get_stratedy();
	Tree* get_tree();
	/* Setters */
	void set_suit(std::string);
	void set_difficulty(bool);
	void set_strategy(std::string);
	void set_current_move(int);
	/* Other */
	int* move(Field&, Menu&); // Make a move
	int* normal_difficult(Field&); // Normal difficulty move
	int* impossible_difficult(Field&); // Impossible difficulty move
	int* next_move(Field&); // Next move using tree
	int* last_move(Field&); // Find last move to win/draw
	void create_impossible_tree_for_zero();
private:
	std::string suit; // zero/cross
	bool difficult; // Impossible difficulty if true
	int currentMove; 
	std::string strategy; // win/draw
	Tree* impossibleTreeZero; // Tree of all possible ways to win/draw playing for zeros
};

