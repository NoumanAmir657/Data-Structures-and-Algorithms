#ifndef CHESS_BOARD
#define CHESS_BOARD

class ChessBoard {
    public:
        ChessBoard(); // for 8 x 8 chessboard
        ChessBoard(int); // for n x n chessboard
        void findSolutions();

    private:
        bool available = true; // bool value that indicates availability
        int squares, norm;
        bool *column, *lD, *rD;
        int *posInRow;
        int howMany;
        void putQueen(int);
        void printBoard();
        void initializeBoard();
        bool flag = false;
};

#endif