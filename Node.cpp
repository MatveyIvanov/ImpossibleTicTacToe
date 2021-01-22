#include "Node.h"


/* Getters */

std::vector<Node*> Node::get_children() {
	return this->children;
}

int* Node::get_player_move() {
	return this->playerMove;
}

int* Node::get_computer_move() {
	return this->computerMove;
}


/* Setters */

void Node::set_computer_move(int move_x, int move_y) {
	this->computerMove[0] = move_x;
	this->computerMove[1] = move_y;
}

void Node::set_player_move(int move_x, int move_y) {
	this->playerMove[0] = move_x;
	this->playerMove[1] = move_y;
}


/* Other */

void Node::add_child(int player_move_x, int player_move_y, int computer_move_x, int computer_move_y) {
	Node* newChild = new Node();
	newChild->set_player_move(player_move_x, player_move_y);
	newChild->set_computer_move(computer_move_x, computer_move_y);
	this->children.push_back(newChild);
}