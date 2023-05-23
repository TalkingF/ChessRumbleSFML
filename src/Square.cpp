#include "Square.h"

Square::Square() : piece(nullptr) {}

void Square::setPiece(Piece* p) {
    piece = p;
}

Piece* Square::getPiece() const {
    return piece;
}

void Square::clear() {
    piece = nullptr;
}