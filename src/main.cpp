#include <iostream>
#include "Reversi/Reversi.hpp"

int main(int argc, char* argv[])
{
    auto reversi = new Reversi();
    reversi->getAllowedPlays();

    return EXIT_SUCCESS;
}