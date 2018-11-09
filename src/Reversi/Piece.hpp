#ifndef REVERSEAI_PIECE_HPP
#define REVERSEAI_PIECE_HPP

enum PieceType{
    EMPTY,
    WHITE,
    BLACK
};

class Piece
{
private:

    PieceType type = PieceType::EMPTY;

public:

    Piece() = default;
};

#endif //REVERSEAI_PIECE_HPP
