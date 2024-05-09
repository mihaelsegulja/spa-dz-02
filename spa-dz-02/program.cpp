#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	
	bool cont;
	do {
		the_game.print();
		the_game.nextGen();
		
		cout << "Continue (1/0): ";
		cin >> cont;
	} while (cont);

	return 0;
}