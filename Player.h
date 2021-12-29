#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <utility>
#include <string>

const int BOARD_SIZE = 3;

class Player {
public:
	Player(char mark_in, std::string name_in)
		: mark(mark_in), name(name_in), point(0) { }

	char get_mark() const {
		return mark;
	}

	std::string get_name() const {
		return name;
	}

	int get_point() const {
		return point;
	}

	void set_point(int new_point) {
		point = new_point;
	}

	virtual std::pair<int, int> play(std::vector<std::vector<char>>& board) = 0;

	virtual ~Player() {}

private:
	char mark;
	std::string name;
	int point;
};

Player* player_factory(const std::string& name, const char mark, const std::string& mode);

#endif