#if !defined(BOARD_H)
#define BOARD_H


class Board {
private:
    char* board;
    int N;
    int countUnocupiedFields;
public:
    enum State { Blank = 0, X='X', O='O' };
    void printBoard();
    void makeMove(int i, int j, State playerSign);
    bool isWinner(int lastMoveI, int lastMoveJ, State playerSign);
    Board();
    Board(int dimension);
    ~Board();
};

#endif // BOARD_H