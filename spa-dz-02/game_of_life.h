#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLUMNS = 40;
	static const unsigned int ROWS = 20;
	bool _gen[ROWS][COLUMNS];
	bool _nextGen[ROWS][COLUMNS];
	bool randVal();
	bool cellTaken(int i, int j);

public:
	game_of_life();
	void nextGen();
	void print();
};

#endif
