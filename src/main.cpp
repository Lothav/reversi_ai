#include <iostream>
#include "Reversi/Reversi.hpp"

int main(int argc, char* argv[])
{
    auto reversi = new Reversi();
    auto moves = reversi->getAllowedPlays();

    std::cout << reversi->toString();
    //reversi->makeAMove(moves[0]);


    return EXIT_SUCCESS;
}