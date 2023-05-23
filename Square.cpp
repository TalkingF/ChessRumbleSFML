#include "Square.h"

Square::Square() : piece(nullptr) {}

void Square::set_piece(Piece* p) {
    piece = p;
}

Piece* Square::get_piece() const {
    return piece;
}

void Square::clear() {
    piece = nullptr;
}
