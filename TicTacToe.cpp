#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe(Player* p1_in, Player* p2_in, int points)
	: board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' ')), points_to_win(points) {
		players[0] = p1_in;
		players[1] = p2_in;
}
	
void TicTacToe::print_board() {
	cout << '\n';
	cout << board[0][0] << '|' << board[0][1] << '|' << board[0][2] << '\n';
	cout << "- - -\n";
	cout << board[1][0] << '|' << board[1][1] << '|' << board[1][2] << '\n';
	cout << "- - -\n";
	cout << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << '\n';
	cout << '\n';
}

bool TicTacToe::check_win(int row, int col) {
	if ((board[row][0] == board[row][1] && board[row][1] == board[row][2]) ||
		(board[0][col] == board[1][col] && board[1][col] == board[2][col]) ||
		(row == col && board[0][0] == board[1][1] && board[1][1] == board[2][2])) {
		return true;
	}

	return false;
}

void TicTacToe::reset_board() {
	board.clear();
	board.resize(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
}
	
void TicTacToe::start_game() {
	int round = 0;
	bool tie = true;
	pair<int, int> choice;

	while (players[0]->get_point() < points_to_win &&
		   players[1]->get_point() < points_to_win) {
		print_board();
		while (round < 9) {
			choice = players[round % 2]->play(board);
			print_board();
			if (check_win(choice.first, choice.second)) {
				tie = false;
				players[round % 2]->set_point(players[round % 2]->get_point() + WIN_POINTS);
				cout << players[round & 2]->get_name() << " gets " << WIN_POINTS << " points!\n";
				break;
			}

			++round;
		}

		if (tie) {
			cout << "Tie! Both players get " << TIE_POINTS << " point(s)!\n";
			players[0]->set_point(players[0]->get_point() + TIE_POINTS);
			players[1]->set_point(players[1]->get_point() + TIE_POINTS);
		}

		cout << "Current points:\n";
		cout << players[0]->get_name() << ": " << players[0]->get_point() << '\n';
		cout << players[1]->get_name() << ": " << players[1]->get_point() << '\n';

		// Clear the board after a game ends
		reset_board();
		round = 0;
	}

	// Print the results
	if (players[0]->get_point() < players[1]->get_point()) {
		cout << players[1]->get_name() << " wins!\n";
	}
	else if (players[0]->get_point() > players[1]->get_point()) {
		cout << players[1]->get_name() << " wins!\n";
	}
	else {
		cout << "Tie! Nobody wins!\n";
	}
}
