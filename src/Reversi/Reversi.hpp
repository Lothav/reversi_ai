#ifndef REVERSEAI_REVERSI_HPP
#define REVERSEAI_REVERSI_HPP

#include <vector>
#include "Table.hpp"

class Reversi
{
    enum Turn {
        PLAYER,
        COMPUTER
    };

private:

    Table* table;
    Turn turn = Turn::PLAYER;

public:

    Reversi()
    {
        table = new Table();

        table->setPiece(3, 3, PieceType::WHITE);
        table->setPiece(4, 4, PieceType::WHITE);
        table->setPiece(3, 4, PieceType::BLACK);
        table->setPiece(4, 3, PieceType::BLACK);
    }

    std::vector<std::array<int, 2>> getAllowedPlays()
    {
        std::vector<std::array<int, 2>> plays;
        auto pieces = table->getPieces();

        PieceType turn_piece_type = PieceType::BLACK;
        PieceType opp_piece_type  = PieceType::WHITE;
        if(turn == Turn::PLAYER) {
            turn_piece_type = PieceType::WHITE;
            opp_piece_type  = PieceType::BLACK;
        }

        for (int l = 0; l < pieces.size(); l++){
            for (int c = 0; c < pieces[l].size(); c++) {
                if(pieces[l][c]->getType() == turn_piece_type){

                    std::array<int, 2> pos = {l, c};
                    std::array<int, 2> move = {l, c};

                    std::vector<std::array<int, 2>> direction_moves = {
                            { 0, +1}, // Right
                            { 0, -1}, // Left
                            {+1,  0}, // Up
                            {-1,  0}, // Down
                            {+1, +1}, // Up Right
                            {-1, +1}, // Down Right
                            {-1, -1}, // Down Left
                            {+1, -1}  // Up Left
                    };

                    for (auto &direction_move: direction_moves) {
                        move = checkMoveDirection(pos, direction_move, opp_piece_type);
                        bool check_m0 = move[0] != pos[0]+direction_move[0];
                        bool check_m1 = move[1] != pos[1]+direction_move[1];

                        if(check_m0 || check_m1) plays.push_back(move);
                    }
                }
            }
        }

        return plays;
    }

    std::array<int, 2> checkMoveDirection(std::array<int, 2> pos, std::array<int, 2> move, PieceType opp_piece_type)
    {
        int a = pos[0];
        int b = pos[1];

        auto pieces = table->getPieces();

        while(a < pieces.size() && b < pieces[a].size() && a >= 0 && b >= 0 &&
              pieces[a += move[0]][b += move[1]]->getType() == opp_piece_type);

        return {a, b};
    }

};

#endif //REVERSEAI_REVERSI_HPP
