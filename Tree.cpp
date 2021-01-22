#include "Tree.h"


/* Getters */

Node* Tree::get_current_node() {
	return this->currentNode;
}

Node* Tree::get_root() {
	return this->root;
}


/* Setters */

void Tree::set_current_node(Node* node) {
	this->currentNode = node;
}


/* Other */

int* Tree::next_move(int* player_move) {
	std::vector<Node*> children = this->currentNode->get_children();
	for (int child = 0; child < this->currentNode->get_children().size(); child++) {
		if (children[child]->get_player_move()[0] == player_move[0] && children[child]->get_player_move()[1] == player_move[1]) {
			this->currentNode = children[child];
			return this->currentNode->get_children()[child]->get_computer_move();
		}
	}
	return NULL;
}