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
            for (auto &cells: lines) {
                cells = new Piece();
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


};

#endif //REVERSEAI_TABLE_HPP
