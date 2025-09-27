#include "piece.hpp"
#include "utils.hpp"
#include "config.hpp"
#include <iostream>

int main()
{
    piece p = piece(piece_t("K", "white", 0), std::pair<int, int>(0,0));
    std::cout << p << std::endl;
}