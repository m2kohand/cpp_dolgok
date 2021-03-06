#ifndef CHESS_H_
#define CHESS_H_
#include "piece.h"
#include <vector>
#include <iostream>

//using namespace chesspiece;

class Field {
Piece* piec;
public:
    Field () : piec (0) {}
    Field (Piece* piec_) : piec(piec_) {}

    void setPiece (Piece* p) { this->piec = p;}
    Piece* getPiece () { return this->piec;}
};

class Board {
Field *board[8];
public:
Board () {
    board [1] = rowOfPawns (true);
    board [6] = rowOfPawns (false);
    board [0] = rowOfMisc (true);
    board [7] = rowOfMisc (false);

    for ( int i = 2; i < 6; ++i)
        board [i] = rowOfEmtpy();
}

Piece* getPiece (int i, int j) {
    return board[i][j].getPiece();
}

private:
    Field* rowOfPawns (bool team1);
    Field* rowOfMisc (bool team1);
    Field* rowOfEmtpy (void);
};
#endif // CHESS_H_

