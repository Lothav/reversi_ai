#include <iostream>
#include "Reversi/Reversi.hpp"

int main(int argc, char* argv[])
{
    auto reversi = new Reversi();
    auto moves = reversi->getAllowedMoves();

    std::cout << reversi->toString();
    reversi->makeAMove(moves[0]);
    std::cout << reversi->toString();


    return EXIT_SUCCESS;
}