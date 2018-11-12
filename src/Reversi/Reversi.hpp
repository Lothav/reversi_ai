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

        table->setPiece(3, 3, PieceType::BLACK);
        table->setPiece(4, 4, PieceType::BLACK);
        table->setPiece(3, 4, PieceType::WHITE);
        table->setPiece(4, 3, PieceType::WHITE);
    }

    std::vector<std::array<int, 2>> getAllowedPlays()
    {
        std::vector<std::array<int, 2>> plays;
        auto pieces = table->getPieces();

        PieceType turn_piece_type = PieceType::BLACK;
        PieceType opp_piece_type = PieceType::WHITE;
        if(turn == Turn::PLAYER) {
            turn_piece_type = PieceType::WHITE;
            opp_piece_type = PieceType::BLACK;
        }

        for (int l = 0; l < pieces.size(); l++){
            for (int c = 0; c < pieces[l].size(); c++) {
                if(pieces[l][c]->getType() == turn_piece_type){

                    std::array<int, 2> pos = {l, c};
                    std::array<int, 2> move = {l, c};

                    // Right
                    move = checkMoveDirection(pos, {0, +1}, opp_piece_type);
                    if(move[1] != pos[1]+1) plays.push_back(move);

                    // Left
                    move = checkMoveDirection(pos, {0, -1}, opp_piece_type);
                    if(move[1] != pos[1]-1) plays.push_back(move);

                    // Up
                    move = checkMoveDirection(pos, {+1, 0}, opp_piece_type);
                    if(move[0] != pos[0]+1) plays.push_back(move);

                    // Down
                    move = checkMoveDirection(pos, {-1, 0}, opp_piece_type);
                    if(move[0] != pos[0]-1) plays.push_back(move);

                    // Upper Right
                    move = checkMoveDirection(pos, {+1, +1}, opp_piece_type);
                    if(move[0] != pos[0]+1) plays.push_back(move);

                    // Down Right
                    move = checkMoveDirection(pos, {-1, +1}, opp_piece_type);
                    if(move[0] != pos[0]-1) plays.push_back(move);

                    // Down Left
                    move = checkMoveDirection(pos, {-1, -1}, opp_piece_type);
                    if(move[0] != pos[0]-1) plays.push_back(move);

                    // Upper Left
                    move = checkMoveDirection(pos, {+1, -1}, opp_piece_type);
                    if(move[0] != pos[0]+1) plays.push_back(move);

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
