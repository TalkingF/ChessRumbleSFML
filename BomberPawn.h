#ifndef BOMBER_PAWN_H
#define BOMBER_PAWN_H

#include "Pawn.h"

class Board; // Forward declaration of Board class

class BomberPawn : public Pawn {
public:
    BomberPawn(bool colour, int row, int col);

    bool legal_move(int new_row, int new_col, const Board& board) override;

private:
    void explode(Board& board, int center_row, int center_col);
};
#endif