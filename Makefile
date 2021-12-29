CXX := g++
CXXFLAGS := -Wall -Werror -pedantic --std=c++11 -g

.PHONY: clean
clean:
	rm -f game

game: driver.cpp TicTacToe.cpp Player.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
