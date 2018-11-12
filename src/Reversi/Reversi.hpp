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

    std::array<int, 2> moveToDirection(std::array<int, 2> pos, std::array<int, 2> move)
    {
        auto pieces = table->getPieces();

        int a = pos[0];
        int b = pos[1];

        do {
            a += move[0];
            b += move[1];
            if(a >= pieces.size() || b >= pieces[a].size() || a < 0 || b < 0){
                return {a - move[0], b - move[1]};
            }
        } while (pieces[a][b]->getType() == getOppositePiece()) ;

        return {a, b};
    }

    void changeTurn()
    {
        turn = turn == PLAYER ? COMPUTER : PLAYER;
    }

    void makeAMove(std::array<int, 2> allowed_play)
    {
        auto pieces = table->getPieces();

        table->setPiece(allowed_play, getTurnPiece());

        for (auto &dm: direction_moves) {
            auto move = moveToDirection(allowed_play, dm);
            int x = move[0];
            int y = move[1];

            bool check_m0 = x != allowed_play[0];
            bool check_m1 = y != allowed_play[1];
            if (check_m0 || check_m1){
                if (pieces[x][y]->getType() == getTurnPiece()){
                    x -= dm[0];
                    y -= dm[1];
                    while(pieces[x][y]->getType() == getOppositePiece()) {
                        pieces[x][y]->setPiece(getTurnPiece());
                        x -= dm[0];
                        y -= dm[1];
                    }
                }
            }
        }

        changeTurn();
    }

    std::vector<std::array<int, 2>> getAllowedMoves()
    {
        auto pieces = table->getPieces();

        std::vector<std::array<int, 2>> plays = {};

        for (int l = 0; l < pieces.size(); l++){
            for (int c = 0; c < pieces[l].size(); c++) {
                if(pieces[l][c]->getType() == getTurnPiece()){
                    std::array<int, 2> move, pos = {l, c};
                    for (auto &direction_move: direction_moves) {
                        move = moveToDirection(pos, direction_move);

                        bool check_m0 = move[0] != pos[0]+direction_move[0];
                        bool check_m1 = move[1] != pos[1]+direction_move[1];

                        if((check_m0 || check_m1) && pieces[move[0]][move[1]]->getType() == EMPTY)
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
