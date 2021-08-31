#include <iostream>
#include "chessboard.h"

ChessBoard::ChessBoard() {
    available = true;
    squares = 8;
    norm = squares - 1;

    initializeBoard();
}

ChessBoard::ChessBoard(int n){
    available = true;
    squares = n;
    norm = squares - 1;
    initializeBoard();
}

void ChessBoard::initializeBoard() {
    register int i;
    column = new bool[squares];
    posInRow = new int[squares];
    lD = new bool[squares*2-1];
    rD = new bool[squares*2-1];

    for (i = 0; i < squares; i++){
        posInRow[i] = -1;
        column[i] = available;
    }

    for(i = 0; i < squares*2-1; ++i){
        lD[i] = available;
        rD[i] = available;
    }

    howMany = 0;
}

void ChessBoard::putQueen(int row) {
    for (int col = 0; col < squares; col++){
        if (column[col] == available && lD[row+col] == available && rD[row-col+norm] == available){
            posInRow[row] = col;
            column[col] = !available;
            lD[row+col] = !available;
            rD[row-col+norm] = !available;

            if (row < squares-1){
                putQueen(row+1);
            }
            else {
                printBoard();
            }
            column[col] = available;
            lD[row+col] = available;
            rD[row-col+norm] = available;
        }
    }
}

void ChessBoard::findSolutions() {
    putQueen(0);
}

void ChessBoard::printBoard() {
    for (int i = 0; i < squares; ++i){
        std::cout << "Position of Queen in row " << i << " is " << posInRow[i] << '\n';
    }
    std::cout << "---------------------------------------------------------------------\n";
}
