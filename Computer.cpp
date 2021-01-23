#include "Computer.h"

/* Getters */

std::string Computer::get_suit() {
	return this->suit;
}

bool Computer::get_difficulty() {
	return this->difficult;
}

std::string Computer::get_stratedy() {
	return this->strategy;
}

Tree* Computer::get_tree() {
	return this->impossibleTreeZero;
}


/* Setters */

void Computer::set_suit(std::string s) {
	this->suit = s;
}

void Computer::set_difficulty(bool d) {
	this->difficult = d;
}

void Computer::set_strategy(std::string s) {
	this->strategy = s;
}

void Computer::set_current_move(int move_num) {
	this->currentMove = move_num;
}


/* Other */

int* Computer::move(Field& field, Menu& menu) {
	if (menu.get_difficulty() == "normal")
		return this->normal_difficult(field); // Normal difficulty move
	else
		return this->impossible_difficult(field); // Impossible difficulty move
}

int* Computer::normal_difficult(Field& field) {
	int suit = (this->get_suit() == "cross") ? 1 : 2;
	return nullptr;
}

int* Computer::impossible_difficult(Field& field) {
	int suit = (this->get_suit() == "cross") ? 1 : 2; // 1 - cross, 2 - zero
	int** f = field.get_field(); // Field
	int* position = new int[2]; // Position to return
	if (suit == 1) { // If computer makes 1st move of the game
		switch (this->currentMove) {
		case 1: { // 1st move
			f[1][1] = 1;
			position[0] = 1;
			position[1] = 1;
			this->currentMove++;
			break;
		}
		case 2: { // 2nd move
			if (f[0][1] == 2 || f[1][0] == 2 || f[1][2] == 2 || f[2][1] == 2) {
				if (f[1][0] == 2 || f[0][1] == 2) {
					f[0][0] = 1;
					position[0] = 0;
					position[1] = 0;
					this->currentMove++;
				}
				else {
					f[2][2] = 1;
					position[0] = 2;
					position[1] = 2;
					this->currentMove++;
				}
			}
			else {
				f[0][1] = 1;
				position[0] = 0;
				position[1] = 1;
				this->currentMove++;
				this->set_strategy("draw");
			}
			break;
		}
		case 3: { // 3rd move
			if (this->get_stratedy() == "win") {
				if (f[0][0] == 1) {
					if (f[2][2] == 0) {
						f[0][0] = f[1][1] = f[2][2] = 3;
						position[0] = 2;
						position[1] = 2;
						this->currentMove = 1;
						field.set_game_over(true);
						field.set_winner("computer");
					}
					else {
						if (f[0][1] == 0) {
							f[0][2] = 1;
							position[0] = 0;
							position[1] = 2;
							this->currentMove++;
						}
						else {
							f[2][0] = 1;
							position[0] = 2;
							position[1] = 0;
							this->currentMove++;
						}
					}
				}
				else {
					if (f[0][0] == 0) {
						f[0][0] = f[1][1] = f[2][2] = 3;
						position[0] = 0;
						position[1] = 0;
						this->currentMove = 1;
						field.set_game_over(true);
						field.set_winner("computer");
					}
					else {
						if (f[2][1] == 0) {
							f[2][0] = 1;
							position[0] = 2;
							position[1] = 0;
							this->currentMove++;
						}
						else {
							f[0][2] = 1;
							position[0] = 0;
							position[1] = 2;
							this->currentMove++;
						}
					}
				}
			}
			else {
				if (f[2][1] == 0) {
					f[2][1] = f[1][1] = f[0][1] = 3;
					position[0] = 2;
					position[1] = 1;
					this->currentMove = 1;
					field.set_game_over(true);
					field.set_winner("computer");
				}
				else {
					if (f[0][0] == 2 || f[0][2] == 2) {
						f[1][2] = 1;
						position[0] = 1;
						position[1] = 2;
						this->currentMove++;
					}
					else {
						if (f[2][2] == 2) {
							f[2][0] = 1;
							position[0] = 2;
							position[1] = 0;
							this->currentMove++;
						}
						else {
							f[2][2] = 1;
							position[0] = 2;
							position[1] = 2;
							this->currentMove++;
						}
					}
				}
			}
			break;
		}
		case 4: { // 4th move
			if (this->get_stratedy() == "win") {
				if (f[0][2] == 1) {
					if (f[0][0] == 1) {
						if (f[0][1] == 2) {
							f[0][2] = f[1][1] = f[2][0] = 3;
							position[0] = 2;
							position[1] = 0;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
						else {
							f[0][0] = f[0][1] = f[0][2] = 3;
							position[0] = 0;
							position[1] = 1;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
					}
					else {
						if (f[2][0] == 2) {
							f[0][2] = f[1][2] = f[2][2] = 3;
							position[0] = 1;
							position[1] = 2;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
						else {
							f[0][2] = f[1][1] = f[2][0] = 3;
							position[0] = 2;
							position[1] = 0;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
					}
				}
				else {
					if (f[0][0] == 1) {
						if (f[1][0] == 2) {
							f[0][2] = f[1][1] = f[2][0] = 3;
							position[0] = 0;
							position[1] = 2;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
						else {
							f[0][0] = f[1][0] = f[2][0] = 3;
							position[0] = 1;
							position[1] = 0;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
					}
					else {
						if (f[0][2] == 2) {
							f[2][0] = f[2][1] = f[2][2] = 3;
							position[0] = 2;
							position[1] = 1;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
						else {
							f[0][2] = f[1][1] = f[2][0] = 3;
							position[0] = 0;
							position[1] = 2;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
					}
				}
			}
			else {
				if (f[2][2] == 0) {
					if (f[1][0] == 0) {
						f[1][0] = f[1][1] = f[1][2] = 3;
						position[0] = 1;
						position[1] = 0;
						this->currentMove = 1;
						field.set_game_over(true);
						field.set_winner("computer");
					}
					else {
						f[2][0] = 1;
						position[0] = 2;
						position[1] = 0;
						this->currentMove++;
					}
				}
				else {
					if (f[2][0] == 1) {
						if (f[0][2] == 0) {
							f[0][2] = f[1][1] = f[2][0] = 3;
							position[0] = 0;
							position[1] = 2;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
						else {
							f[1][2] = 1;
							position[0] = 1;
							position[1] = 2;
							this->currentMove++;
						}
					}
					else {
						if (f[0][0] == 0) {
							f[0][0] = f[1][1] = f[2][2] = 3;
							position[0] = 0;
							position[1] = 0;
							this->currentMove = 1;
							field.set_game_over(true);
							field.set_winner("computer");
						}
						else {
							f[1][0] = 1;
							position[0] = 1;
							position[1] = 0;
							this->currentMove++;
						}
					}
				}
			}
			break;
		}
		case 5: { // 5th move
			position = this->last_move(field);
			break;
		}
		}
	}
	else { // If computer makes 2nd move of the game (plays for zeros)
		position = this->next_move(field); // Get next move from tree
	}
	return position;
}

int* Computer::next_move(Field& field) {
	if (!this->impossibleTreeZero->get_current_node()->get_children().empty() || this->impossibleTreeZero->get_current_node() == this->impossibleTreeZero->get_root()) { // If there are available next moves in tree
		if (!this->impossibleTreeZero->get_current_node()->get_children().empty()) { // If there are available next moves in tree
			std::vector<Node*> currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
			for (int i = 0; i < currentChildren.size(); i++) {
				if (currentChildren[i]->get_player_move()[0] == field.get_player_last_move()[0] && currentChildren[i]->get_player_move()[1] == field.get_player_last_move()[1]) { // If exists computer move according to player's move
					this->impossibleTreeZero->set_current_node(currentChildren[i]); // Change current node
					return currentChildren[i]->get_computer_move();
				}
			}
		}
	}
	return this->last_move(field); // Make last move to win or draw
}

int* Computer::last_move(Field& field) {
	int suit = (this->get_suit() == "cross") ? 1 : 2; // 1 - cross, 2 - zero
	int** f = field.get_field(); // Field
	int* position = new int[2]; // Position to return
	/* Find available cell to move */
	if ((f[0][0] == suit && f[0][1] == suit && f[0][2] == 0) || (f[0][0] == suit && f[0][1] == 0 && f[0][2] == suit) || (f[0][0] == 0 && f[0][1] == suit && f[0][2] == suit)) {
		f[0][0] = f[0][1] = f[0][2] = suit + 2;
		if (f[0][0] == 0) { position[0] = 0; position[1] = 0; }
		else if (f[0][1] == 0) { position[0] = 0; position[1] = 1; }
		else { position[0] = 0; position[1] = 2; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[1][0] == suit && f[1][1] == suit && f[1][2] == 0) || (f[1][0] == suit && f[1][1] == 0 && f[1][2] == suit) || (f[1][0] == 0 && f[1][1] == suit && f[1][2] == suit)) {
		f[1][0] = f[1][1] = f[1][2] = suit + 2;
		if (f[1][0] == 0) { position[0] = 1; position[1] = 0; }
		else if (f[1][1] == 0) { position[0] = 1; position[1] = 1; }
		else { position[0] = 1; position[1] = 2; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[2][0] == suit && f[2][1] == suit && f[2][2] == 0) || (f[2][0] == suit && f[2][1] == 0 && f[2][2] == suit) || (f[2][0] == 0 && f[2][1] == suit && f[2][2] == suit)) {
		f[2][0] = f[2][1] = f[2][2] = suit + 2;
		if (f[2][0] == 0) { position[0] = 2; position[1] = 0; }
		else if (f[2][1] == 0) { position[0] = 2; position[1] = 1; }
		else { position[0] = 2; position[1] = 2; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[0][0] == suit && f[1][0] == suit && f[2][0] == 0) || (f[0][0] == suit && f[1][0] == 0 && f[2][0] == suit) || (f[0][0] == 0 && f[1][0] == suit && f[2][0] == suit)) {
		f[0][0] = f[1][0] = f[2][0] = suit + 2;
		if (f[0][0] == 0) { position[0] = 0; position[1] = 0; }
		else if (f[1][0] == 0) { position[0] = 1; position[1] = 0; }
		else { position[0] = 2; position[1] = 0; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[0][1] == suit && f[1][1] == suit && f[2][1] == 0) || (f[0][1] == suit && f[1][1] == 0 && f[2][1] == suit) || (f[0][1] == 0 && f[1][1] == suit && f[2][1] == suit)) {
		f[0][1] = f[1][1] = f[2][1] = suit + 2;
		if (f[0][1] == 0) { position[0] = 0; position[1] = 1; }
		else if (f[1][1] == 0) { position[0] = 1; position[1] = 1; }
		else { position[0] = 2; position[1] = 1; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[0][2] == suit && f[1][2] == suit && f[2][2] == 0) || (f[0][2] == suit && f[1][2] == 0 && f[2][2] == suit) || (f[0][2] == 0 && f[1][2] == suit && f[2][2] == suit)) {
		f[0][2] = f[1][2] = f[2][2] = suit + 2;
		if (f[0][2] == 0) { position[0] = 0; position[1] = 2; }
		else if (f[1][2] == 0) { position[0] = 1; position[1] = 2; }
		else { position[0] = 2; position[1] = 2; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[0][0] == suit && f[1][1] == suit && f[2][2] == 0) || (f[0][0] == suit && f[1][1] == 0 && f[2][2] == suit) || (f[0][0] == 0 && f[1][1] == suit && f[2][2] == suit)) {
		f[0][0] = f[1][1] = f[2][2] = suit + 2;
		if (f[0][0] == 0) { position[0] = 0; position[1] = 0; }
		else if (f[1][1] == 0) { position[0] = 1; position[1] = 1; }
		else { position[0] = 2; position[1] = 2; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else if ((f[0][2] == suit && f[1][1] == suit && f[2][0] == 0) || (f[0][2] == suit && f[1][1] == 0 && f[2][0] == suit) || (f[0][2] == 0 && f[1][1] == suit && f[2][0] == suit)) {
		f[0][2] = f[1][1] = f[2][0] = suit + 2;
		if (f[0][2] == 0) { position[0] = 0; position[1] = 2; }
		else if (f[1][1] == 0) { position[0] = 1; position[1] = 1; }
		else { position[0] = 2; position[1] = 0; }
		field.set_game_over(true);
		field.set_winner("computer");
	}
	else {
		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				if (f[row][column] == 0) {
					f[row][column] = suit;
					position[0] = row;
					position[1] = column;
					field.set_game_over(true);
					field.set_winner("draw");
					return position;
				}
			}
		}
	}
	return position;
}

void Computer::create_impossible_tree_for_zero() {
	int* position = new int[2];

	/* First possible moves */
	this->impossibleTreeZero->get_current_node()->add_child(0, 0, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(0, 1, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(0, 2, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(1, 0, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(1, 1, 0, 0);
	this->impossibleTreeZero->get_current_node()->add_child(1, 2, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(2, 0, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(2, 1, 1, 1);
	this->impossibleTreeZero->get_current_node()->add_child(2, 2, 1, 1);
	/* End of first possible moves */

	std::vector<Node*> currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* All possible 2nd moves */
	currentChildren[0]->add_child(0, 1, 0, 2);
	currentChildren[0]->add_child(0, 2, 0, 1);
	currentChildren[0]->add_child(1, 0, 2, 0);
	currentChildren[0]->add_child(1, 2, 0, 2);
	currentChildren[0]->add_child(2, 0, 1, 0);
	currentChildren[0]->add_child(2, 1, 2, 0);
	currentChildren[0]->add_child(2, 2, 2, 1);

	currentChildren[1]->add_child(0, 0, 0, 2);
	currentChildren[1]->add_child(0, 2, 0, 1);
	currentChildren[1]->add_child(1, 0, 0, 0);
	currentChildren[1]->add_child(1, 2, 0, 2);
	currentChildren[1]->add_child(2, 0, 0, 0);
	currentChildren[1]->add_child(2, 1, 0, 0);
	currentChildren[1]->add_child(2, 2, 0, 2);

	currentChildren[2]->add_child(0, 0, 0, 1);
	currentChildren[2]->add_child(0, 1, 0, 0);
	currentChildren[2]->add_child(1, 0, 0, 0);
	currentChildren[2]->add_child(1, 2, 2, 2);
	currentChildren[2]->add_child(2, 0, 0, 1);
	currentChildren[2]->add_child(2, 1, 2, 2);
	currentChildren[2]->add_child(2, 2, 1, 2);

	currentChildren[3]->add_child(0, 0, 2, 0);
	currentChildren[3]->add_child(0, 1, 0, 0);
	currentChildren[3]->add_child(0, 2, 0, 0);
	currentChildren[3]->add_child(1, 2, 0, 0);
	currentChildren[3]->add_child(2, 0, 0, 0);
	currentChildren[3]->add_child(2, 1, 2, 0);
	currentChildren[3]->add_child(2, 2, 2, 0);

	currentChildren[4]->add_child(0, 1, 2, 1);
	currentChildren[4]->add_child(0, 2, 2, 0);
	currentChildren[4]->add_child(1, 0, 1, 2);
	currentChildren[4]->add_child(1, 2, 1, 0);
	currentChildren[4]->add_child(2, 0, 0, 2);
	currentChildren[4]->add_child(2, 1, 0, 1);
	currentChildren[4]->add_child(2, 2, 2, 0);

	currentChildren[5]->add_child(0, 0, 0, 2);
	currentChildren[5]->add_child(0, 1, 0, 2);
	currentChildren[5]->add_child(0, 2, 2, 2);
	currentChildren[5]->add_child(1, 0, 0, 2);
	currentChildren[5]->add_child(2, 0, 2, 2);
	currentChildren[5]->add_child(2, 1, 2, 2);
	currentChildren[5]->add_child(2, 2, 0, 2);

	currentChildren[6]->add_child(0, 0, 1, 0);
	currentChildren[6]->add_child(0, 1, 0, 0);
	currentChildren[6]->add_child(0, 2, 0, 1);
	currentChildren[6]->add_child(1, 0, 0, 0);
	currentChildren[6]->add_child(1, 2, 2, 2);
	currentChildren[6]->add_child(2, 1, 2, 2);
	currentChildren[6]->add_child(2, 2, 2, 1);

	currentChildren[7]->add_child(0, 0, 2, 0);
	currentChildren[7]->add_child(0, 1, 0, 0);
	currentChildren[7]->add_child(0, 2, 2, 2);
	currentChildren[7]->add_child(1, 0, 2, 0);
	currentChildren[7]->add_child(1, 2, 2, 2);
	currentChildren[7]->add_child(2, 0, 2, 2);
	currentChildren[7]->add_child(2, 2, 2, 0);

	currentChildren[8]->add_child(0, 0, 2, 1);
	currentChildren[8]->add_child(0, 1, 0, 2);
	currentChildren[8]->add_child(0, 2, 1, 2);
	currentChildren[8]->add_child(1, 0, 2, 0);
	currentChildren[8]->add_child(1, 2, 0, 2);
	currentChildren[8]->add_child(2, 0, 2, 1);
	currentChildren[8]->add_child(2, 1, 2, 0);

	/* All possible 3rd moves that make sense */
	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[0]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();

	/* --1-- */
	currentChildren[0]->add_child(2, 0, 1, 0);
	currentChildren[1]->add_child(2, 1, 2, 0);
	currentChildren[2]->add_child(0, 2, 0, 1);
	currentChildren[3]->add_child(2, 0, 1, 0);
	currentChildren[4]->add_child(1, 2, 0, 2);
	currentChildren[5]->add_child(0, 2, 0, 1);
	currentChildren[6]->add_child(0, 1, 0, 2);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[1]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --2-- */
	currentChildren[0]->add_child(2, 0, 1, 0);
	currentChildren[1]->add_child(2, 2, 1, 2);
	currentChildren[2]->add_child(2, 2, 2, 0);
	currentChildren[3]->add_child(2, 0, 2, 2);
	currentChildren[4]->add_child(2, 2, 2, 1);
	currentChildren[5]->add_child(2, 2, 2, 0);
	currentChildren[6]->add_child(2, 0, 2, 1);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[2]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --3-- */
	currentChildren[0]->add_child(2, 1, 2, 2);
	currentChildren[1]->add_child(2, 2, 1, 2);
	currentChildren[2]->add_child(2, 2, 1, 2);
	currentChildren[3]->add_child(0, 0, 0, 1);
	currentChildren[4]->add_child(2, 1, 2, 2);
	currentChildren[5]->add_child(0, 0, 0, 1);
	currentChildren[6]->add_child(1, 0, 2, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[3]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --4-- */
	currentChildren[0]->add_child(0, 2, 0, 1);
	currentChildren[1]->add_child(2, 2, 2, 0);
	currentChildren[2]->add_child(2, 2, 1, 2);
	currentChildren[3]->add_child(2, 2, 0, 2);
	currentChildren[4]->add_child(2, 2, 2, 1);
	currentChildren[5]->add_child(0, 2, 2, 2);
	currentChildren[6]->add_child(0, 2, 1, 2);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[4]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --5-- */
	currentChildren[0]->add_child(0, 2, 2, 0);
	currentChildren[0]->add_child(1, 0, 1, 2);
	currentChildren[0]->add_child(1, 2, 1, 0);
	currentChildren[0]->add_child(2, 0, 0, 2);
	currentChildren[0]->add_child(2, 2, 2, 0);

	currentChildren[1]->add_child(1, 0, 1, 2);

	currentChildren[2]->add_child(0, 1, 2, 1);
	currentChildren[2]->add_child(0, 2, 2, 0);
	currentChildren[2]->add_child(2, 0, 0, 2);
	currentChildren[2]->add_child(2, 1, 0, 1);
	currentChildren[2]->add_child(2, 2, 0, 2);

	currentChildren[3]->add_child(2, 0, 0, 2);

	currentChildren[4]->add_child(0, 1, 2, 1);

	currentChildren[5]->add_child(0, 2, 2, 0);

	currentChildren[6]->add_child(1, 0, 1, 2);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[5]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --6-- */
	currentChildren[0]->add_child(2, 0, 1, 0);
	currentChildren[1]->add_child(2, 0, 0, 0);
	currentChildren[2]->add_child(0, 0, 0, 1);
	currentChildren[3]->add_child(2, 0, 0, 0);
	currentChildren[4]->add_child(0, 0, 1, 0);
	currentChildren[5]->add_child(0, 0, 0, 2);
	currentChildren[6]->add_child(2, 0, 2, 1);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[6]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --7-- */
	currentChildren[0]->add_child(1, 2, 0, 2);
	currentChildren[1]->add_child(2, 2, 2, 1);
	currentChildren[2]->add_child(2, 1, 2, 2);
	currentChildren[3]->add_child(2, 2, 2, 1);
	currentChildren[4]->add_child(0, 0, 1, 0);
	currentChildren[5]->add_child(0, 0, 1, 0);
	currentChildren[6]->add_child(0, 1, 0, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[7]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --8-- */
	currentChildren[0]->add_child(0, 2, 0, 1);
	currentChildren[1]->add_child(2, 2, 2, 0);
	currentChildren[2]->add_child(0, 0, 0, 1);
	currentChildren[3]->add_child(0, 2, 0, 0);
	currentChildren[4]->add_child(0, 0, 0, 2);
	currentChildren[5]->add_child(0, 0, 1, 0);
	currentChildren[6]->add_child(0, 2, 1, 2);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[8]);
	currentChildren = this->impossibleTreeZero->get_current_node()->get_children();
	/* --9-- */
	currentChildren[0]->add_child(0, 1, 0, 2);
	currentChildren[1]->add_child(2, 0, 2, 1);
	currentChildren[2]->add_child(1, 0, 0, 0);
	currentChildren[3]->add_child(0, 2, 1, 2);
	currentChildren[4]->add_child(2, 0, 2, 1);
	currentChildren[5]->add_child(0, 1, 0, 0);
	currentChildren[6]->add_child(0, 2, 1, 2);


	/* All possible 4th moves that make sense */
	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[0]);
	/* --1-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(1, 2, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(1, 2, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(2, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(2, 2, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(2, 2, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(1, 2, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(2, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(2, 0, 1, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[1]);
	/* --2-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(1, 2, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(1, 0, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(0, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(1, 2, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(1, 0, 0, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[2]);
	/* --3-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(1, 0, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(1, 0, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 0, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 1, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(1, 0, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(2, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 0, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 1, 0, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[3]);
	/* --4-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 0, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 1, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(2, 0, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 1, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(0, 0, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 0, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 1, 0, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[4]);
	/* --5-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[1]->add_child(0, 2, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[1]->add_child(2, 0, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[2]->add_child(2, 0, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[3]->add_child(1, 2, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[3]->add_child(2, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[4]->add_child(1, 0, 1, 2);

	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(2, 1, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(0, 1, 2, 1);

	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 0, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(0, 2, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[1]->add_child(2, 1, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[3]->add_child(0, 2, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[4]->add_child(0, 1, 2, 1);

	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(0, 1, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(1, 0, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(1, 2, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(1, 0, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 1, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(2, 1, 0, 1);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[5]);
	/* --6-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 2, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(2, 2, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 1, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(2, 2, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 1, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 2, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(2, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 1, 0, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[6]);
	/* --7-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 2, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 1, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(1, 2, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(0, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(0, 1, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 1, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 2, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(1, 2, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(1, 2, 0, 2);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[7]);
	/* --8-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(1, 2, 2, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(1, 0, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(2, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(2, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(1, 2, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(1, 0, 0, 0);

	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root()->get_children()[8]);
	/* --9-- */
	this->impossibleTreeZero->get_current_node()->get_children()[0]->get_children()[0]->add_child(2, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(0, 0, 1, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[1]->get_children()[0]->add_child(1, 0, 0, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 0, 2, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[2]->get_children()[0]->add_child(2, 1, 2, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(0, 0, 0, 1);
	this->impossibleTreeZero->get_current_node()->get_children()[3]->get_children()[0]->add_child(0, 1, 0, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[4]->get_children()[0]->add_child(0, 1, 0, 0);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(0, 2, 1, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[5]->get_children()[0]->add_child(1, 2, 0, 2);
	this->impossibleTreeZero->get_current_node()->get_children()[6]->get_children()[0]->add_child(1, 0, 0, 0);


	this->impossibleTreeZero->set_current_node(this->impossibleTreeZero->get_root());
}
