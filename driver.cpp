#include "TicTacToe.h"
#include <iostream>
using namespace std;

int main() {
	bool has_AI = false;
	char mode = ' ';
	string name;
	Player* p1 = nullptr;
	Player* p2 = nullptr;
	int points_to_win;

	cout << "Choose the mode of Player 1 (A/H): ";
	cin >> mode;
	if (mode == 'A') {
		has_AI = true;
		p1 = player_factory("AI", 'o', "AI");
	}
	else {
		cout << "Enter the name of Player 1: ";
		cin >> name;
		p1 = player_factory(name, 'o', "Human");
	}

	cout << "Choose the mode of Player 2 (A/H): ";
	cin >> mode;
	if (mode == 'A') {
		// At most one AI player allowed
		if (has_AI) {
			cerr << "There should be at least one human player!\n";
			exit(1);
		}
		else {
			p2 = player_factory("AI", 'x', "AI");
		}
	}
	else {
		cout << "Enter the name of Player 2: ";
		cin >> name;
		p2 = player_factory(name, 'x', "Human");
	}
	
	cout << "Enter the points to win the game: ";
	cin >> points_to_win;

	TicTacToe game(p1, p2, points_to_win);
	game.start_game();

	delete p1;
	delete p2;

	return 0;
}