#include "game_of_life.h"
#include <ctime>

bool game_of_life::randVal(){
	return rand() % 4 == 0;
}

bool game_of_life::cellTaken(int i, int j){
	return i >= 0 && i < ROWS && j >= 0 && j < COLUMNS && _gen[i][j];
}

game_of_life::game_of_life(){
    srand(time(nullptr));
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLUMNS; j++) {
            _gen[i][j] = randVal();
        }
    }
}

void game_of_life::nextGen(){
    bool tempNextGen[ROWS][COLUMNS];

    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLUMNS; j++) {
            
            int aliveNeighbours = 0;
            
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    if (a == 0 && b == 0) {
                        continue;
                    }
                    else if(cellTaken(i + a, j + b)) {
                        aliveNeighbours++;
                    }
                }
            }

            _nextGen[i][j] = (_gen[i][j] && (aliveNeighbours == 2 || aliveNeighbours == 3)) || (!_gen[i][j] && aliveNeighbours == 3);
        }
    }

    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLUMNS; j++) {
            _gen[i][j] = _nextGen[i][j];
        }
    }
}

void game_of_life::print(){

    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLUMNS; j++) {
            if(_gen[i][j]) {
                cout << "# ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}
