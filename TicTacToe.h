#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Player.h"

class TicTacToe {
public:
	TicTacToe(Player* p1_in, Player* p2_in, int points);

	void print_board();

	bool check_win(int row, int col);

	void reset_board();

	void start_game();

private:
	Player* players[2];
	std::vector<std::vector<char>> board;
	int points_to_win;
	static const int WIN_POINTS = 3;
	static const int TIE_POINTS = 1;
};

#endif