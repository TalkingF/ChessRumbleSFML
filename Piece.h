#ifndef PIECE_H
#define PIECE_H

#include "Board.h"

class Piece {
protected:
    bool colour; //black or white.
    int row; //what row on the board.
    int col; //what column on the the board.
public:
    Piece(bool colour_, int row_, int col_);

    bool get_colour(); //getter for colour.

    int get_row(); //getter for row.

    int get_col(); //getter for column.

    void set_position(int new_row, int new_col);

    virtual bool legal_move(int new_row, int new_col, const Board& board) = 0; //checks if the move the piece is making is legal.

    virtual char get_specific_piece() = 0;

};

 #endif


