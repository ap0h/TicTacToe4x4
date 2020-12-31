#if !defined(BOARD_H)
#define BOARD_H


class Board {
private:
    enum Result { PLAYER_WIN = 1, BOT_WIN = -1, DRAW = 0 };
    char* board;
    int N;
    int countUnocupiedFields;
    int minimax(char* board, int depth, bool isMaximazerTurn, int alpha, int beta);
    Result checkWinner();
public:
    char PlayerSign;
    char ComputerSign;
    enum State { Blank = 0, X='X', O='O' };
    void computerMove();
    void printBoard();
    void makeMove(int i, int j, State playerSign);
    bool isWinner(int lastMoveI, int lastMoveJ, State playerSign);
    Board();
    Board(int dimension);
    ~Board();
};

#endif // BOARD_H