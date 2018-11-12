#ifndef REVERSEAI_TABLE_HPP
#define REVERSEAI_TABLE_HPP

#include <array>
#include "Piece.hpp"

class Table
{

private:

    const static int TABLE_SIZE = 8;
    std::array<std::array<Piece*, TABLE_SIZE>, TABLE_SIZE> pieces = {};

public:

    Table()
    {
        for (auto &lines: pieces){
            for (auto &cell: lines) {
                cell = new Piece();
            }
        }
    }

    void setPiece(std::array<int, 2> pos, PieceType type)
    {
        if(pos[0] >= TABLE_SIZE || pos[1] >= TABLE_SIZE){
            return;
        }

        pieces[pos[0]][pos[1]]->setPiece(type);
    }

    std::array<std::array<Piece*, TABLE_SIZE>, TABLE_SIZE> getPieces()
    {
        return pieces;
    };

};

#endif //REVERSEAI_TABLE_HPP
