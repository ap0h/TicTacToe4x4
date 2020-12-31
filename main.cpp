#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.cpp"
#include "Board.h"


int main(int argv, char** argc)
{
    using namespace std;
  

    Board* board = new Board();
    board->makeMove(3, 3, board->X);
    board->makeMove(2, 2, board->X);
    board->makeMove(1, 1, board->X);
    board->makeMove(0, 0, board->X);

    board->printBoard();
    if ( board->isWinner(2, 2, board->X)) {
        cout << "X win" << endl;
    }

    return 0;
}
