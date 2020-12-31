#include <cstring>
#include <iostream>
#include "Board.h"

void Board::printBoard()
{
    std::cout << "*BOARD*";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)
        {
            std::cout << board[i * N + j];
            if (board[i * N + j] == 0)
            {
                std::cout << "- ";
            }
            else if (board[i * N + j] != 0)
            {
                std::cout << ' ';
            }
        }
    }
    std::cout << std::endl
              << "*******" << std::endl;
}

void Board::makeMove(int i, int j, State playerSign)
{
    if (board[i * N + j] == 0)
    {
        board[i * N + j] = playerSign;
        countUnocupiedFields--;
    }
    else
        std::cout << "Invalid move!" << std::endl;
}
bool Board::isWinner(int lastMoveI, int lastMoveJ, State playerSign)
{
    

    // column
    for (int i = 0; i < N; i++)
    {
        if (board[lastMoveJ + i * N] != playerSign)
            break;
        if (i == N - 1)
            return true;
    }

    // row
    
    int iN = lastMoveI * N;
    for (int j = 0; j < N; j++)
    {
        if (board[iN + j] != playerSign)
        {
            break;
        }
        if (j == N - 1)
            return true;
    }
    
    
    // diag
    if (lastMoveI == lastMoveJ)
    { 
        for (int i = 0; i < N; i++)
        {
            if (board[i * N + i] != playerSign)
                break;
            if(i == N - 1)
                return true;
        }
    }

    // anti diag
    if (lastMoveI + lastMoveJ == N - 1)
    {
          for (int i = 0; i < N; i++)
        {
            if (board[i * N + (N - 1) - i] != playerSign)
                break;
            if(i == N - 1)
                return true;
        }
    }

    // check squares

    return false;
}

Board::Board()
{
    N = 4;
    board = new char[16];
    memset(board, 0, 16);
    countUnocupiedFields = 16;
}
Board::Board(int dimension)
{
    N = dimension;
    int N2 = N * N;
    board = new char[N2];
    memset(board, 0, N2);
    countUnocupiedFields = N2;
}

Board::~Board()
{
    if (board != nullptr)
        delete board;
}
