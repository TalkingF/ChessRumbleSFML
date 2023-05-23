#ifndef SQUARE_H
#define SQUARE_H


class Piece;
class Square {
private:
    Piece* piece;

public:
    Square();

    void set_piece(Piece* p);

    Piece* get_piece() const;

    void clear();
};

#endif
