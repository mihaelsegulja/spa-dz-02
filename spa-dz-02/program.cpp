#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	
	do {
		the_game.print();
		the_game.nextGen();
		
		this_thread::sleep_for(chrono::milliseconds(5));
	} while (1);

	return 0;
}