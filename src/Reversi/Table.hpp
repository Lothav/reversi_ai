#ifndef REVERSEAI_TABLE_HPP
#define REVERSEAI_TABLE_HPP

#include <array>
#include "Piece.hpp"

class Table
{

private:

    std::array<std::array<Piece*, 8>, 8> pieces = {};

public:

    Table()
    {
        for (auto &lines: pieces){
            for (auto &cells: lines) {
                cells = new Piece();
            }
        }
    }


};

#endif //REVERSEAI_TABLE_HPP
