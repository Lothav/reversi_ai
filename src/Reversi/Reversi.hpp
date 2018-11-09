#ifndef REVERSEAI_REVERSI_HPP
#define REVERSEAI_REVERSI_HPP

#include "Table.hpp"

class Reversi
{
private:

    Table* table;

public:

    Reversi()
    {
        table = new Table();

        table->setPiece(3, 3, PieceType::BLACK);
        table->setPiece(4, 4, PieceType::BLACK);
        table->setPiece(3, 4, PieceType::WHITE);
        table->setPiece(4, 3, PieceType::WHITE);
    }

};

#endif //REVERSEAI_REVERSI_HPP
