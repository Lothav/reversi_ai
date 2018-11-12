#ifndef REVERSEAI_TABLE_HPP
#define REVERSEAI_TABLE_HPP

#include <array>
#include "Piece.hpp"

class Table
{

public:
    const static int TABLE_SIZE = 8;

private:

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

    void setPiece(int i, int j, PieceType type)
    {
        if(i >= TABLE_SIZE || j >= TABLE_SIZE){
            return;
        }

        pieces[i][j]->setPiece(type);
    }

    std::array<std::array<Piece*, TABLE_SIZE>, TABLE_SIZE> getPieces()
    {
        return pieces;
    };

};

#endif //REVERSEAI_TABLE_HPP
