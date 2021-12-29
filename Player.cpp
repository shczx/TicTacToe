#include "Player.h"
#include <iostream>
#include <utility>
using namespace std;

class InvalidPositionError : public std::exception {
public:
	InvalidPositionError(const string& msg_in) : err_msg(msg_in) { }

	const char* what() const noexcept override { return err_msg.c_str();  }
private:
	string err_msg;
};

class HumanPlayer : public Player {
public:
	HumanPlayer(const char mark_in, const string& name_in)
		: Player(mark_in, name_in) { }

	pair<int, int> play(vector<vector<char>>& board) override {
		cout << "It's your turn, " << get_name() << "!\n";
		
		int row = 0, col = 0;
		bool finish = false;
		char choice = ' ';

		while (!finish) {
			cout << "Input a valid position in the format of row[space]col: ";
			cin >> row >> col;

			// Check the user input
			try {
				check_input(row, col, board);
			}
			catch (const InvalidPositionError& e) {
				cout << e.what() << '\n';
				continue;
			}

			// User can either finish their turn or re-enter a position
			cout << "Finish your turn?[y/n]: ";
			cin >> choice;
			if (choice == 'y') {
				board[row][col] = get_mark();
				break;
			}
		}

		return { row, col };
	}

	void check_input(int row, int col, vector<vector<char>>& board) {
		if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
			throw InvalidPositionError("Invalid position! It may be beyond the size of the board or it may be occupied.");
		}
	}
};

class AIPlayer : public Player {
public:
	AIPlayer(const char mark_in, const string& name_in)
		: Player(mark_in, name_in) { }

	pair<int, int> play(vector<vector<char>>& board) override {
		cout << "AI plays:\n";
		int row = 0, col = 0;

		// AI player simply chooses a position that hasn't been marked
		for (; row < BOARD_SIZE; ++row) {
			for (; col < BOARD_SIZE; ++col) {
				if (board[row][col] == ' ') {
					board[row][col] = get_mark();
				}
			}
		}

		return { row, col };
	}
};

// Produce different players
Player* player_factory(const string& name, const char mark, const string& mode) {
	if (mode == "Human") {
		return new HumanPlayer(mark, name);
	}
	
	return new AIPlayer(mark, name);
}