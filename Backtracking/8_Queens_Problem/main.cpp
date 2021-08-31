#include <iostream>
#include "chessboard.h"

int main() {
    ChessBoard *c = new ChessBoard();
    c->findSolutions();
    std::cin.get();
}