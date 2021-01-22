#pragma once
#include "Node.h"
class Tree
{
public:
	Tree() {
		root = new Node;
		currentNode = root;
	}
	/* Getters */
	Node* get_current_node(); // Returns current node (step)
	Node* get_root(); // Returns root of the tree
	/* Setters */
	void set_current_node(Node*); // Set current node (step)
	/* Other */
	int* next_move(int*); // Next move using the tree, returns computer's move (depends on player's move)
private:
	Node* root; // Root of the tree
	Node* currentNode; // Current node of the tree (current step)
};

