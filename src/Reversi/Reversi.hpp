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

    const std::vector<std::array<int, 2>> direction_moves = {
            { 0, +1}, // Right
            { 0, -1}, // Left
            {+1,  0}, // Up
            {-1,  0}, // Down
            {+1, +1}, // Up Right
            {-1, +1}, // Down Right
            {-1, -1}, // Down Left
            {+1, -1}  // Up Left
    };

public:

    Reversi()
    {
        table = new Table();

        table->setPiece({3, 3}, PieceType::WHITE);
        table->setPiece({4, 4}, PieceType::WHITE);
        table->setPiece({3, 4}, PieceType::BLACK);
        table->setPiece({4, 3}, PieceType::BLACK);
    }

    PieceType getTurnPiece()
    {
        return turn == PLAYER ? WHITE : BLACK;
    }

    PieceType getOppositePiece()
    {
        return turn == PLAYER ? BLACK : WHITE;
    }

    std::array<int, 2> checkMoveDirection(std::array<int, 2> pos, std::array<int, 2> move)
    {
        int a = pos[0];
        int b = pos[1];

        auto pieces = table->getPieces();

        while(a < pieces.size() && b < pieces[a].size() && a >= 0 && b >= 0 &&
              pieces[a += move[0]][b += move[1]]->getType() == getOppositePiece());

        return {a - move[0], b - move[1]};
    }

    void changeTurn()
    {
        turn = turn == PLAYER ? COMPUTER : PLAYER;
    }

    void makeAMove(std::array<int, 2> allowed_play)
    {
        auto pieces = table->getPieces();

        table->setPiece(allowed_play, getTurnPiece());

        for (auto &direction_move: direction_moves) {
            auto move = checkMoveDirection(allowed_play, direction_move);
            int x = move[0];
            int y = move[1];

            if (x != allowed_play[0] && y != allowed_play[1]){
                if (pieces[x][y]->getType() == getTurnPiece()){
                    do {
                        x -= direction_move[0];
                        y -= direction_move[1];
                        pieces[x][y]->setPiece(getTurnPiece());
                    } while(pieces[x][y]->getType() == getOppositePiece());
                }
            }
        }

        changeTurn();
    }

    std::vector<std::array<int, 2>> getAllowedPlays()
    {
        auto pieces = table->getPieces();

        std::vector<std::array<int, 2>> plays = {};

        PieceType turn_piece_type = getTurnPiece();
        PieceType opp_piece_type  = getOppositePiece();

        for (int l = 0; l < pieces.size(); l++){
            for (int c = 0; c < pieces[l].size(); c++) {
                if(pieces[l][c]->getType() == turn_piece_type){

                    std::array<int, 2> pos  = {l, c};
                    std::array<int, 2> move = {l, c};

                    for (auto &direction_move: direction_moves) {
                        move = checkMoveDirection(pos, direction_move);
                        if(move[0] != pos[0] && move[1] != pos[1])
                            plays.push_back(move);
                    }
                }
            }
        }

        return plays;
    }

    std::string toString()
    {
        return "Current Table: \n" + table->toString();
    }

};

#endif //REVERSEAI_REVERSI_HPP
