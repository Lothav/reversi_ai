#include <iostream>
#include "Reversi/Reversi.hpp"

int main(int argc, char* argv[])
{
    auto reversi = new Reversi();
    std::cout << reversi->toString();

    auto moves = reversi->getAllowedMoves();
    int i = 0;
    while (!moves.empty()) {
        std::cout << "Making move on: (" << std::to_string(moves[0][0]) << ", " << std::to_string(moves[0][1]) << ")" << std::endl;
        reversi->makeAMove(moves[0]);
        std::cout << reversi->toString();
        moves = reversi->getAllowedMoves();
    }

    return EXIT_SUCCESS;
}