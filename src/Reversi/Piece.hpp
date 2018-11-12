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

    void setPiece(PieceType type)
    {
        this->type = type;
    }

    PieceType getType()
    {
        return type;
    }
};

#endif //REVERSEAI_PIECE_HPP
