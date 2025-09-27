#include <unordered_set>
#include "utils.hpp"
#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace config
{
    inline std::unordered_set<std::string> TYPES = 
    {
        "K",
        "Q",
        "R",
        "N",
        "B",
        "P"
    };
    inline std::unordered_set<piece_t, piece_t::hash_fn> PIECES = {
        piece_t("K", "black", 0),
        piece_t("K", "white", 0),
        piece_t("Q", "black", 0),
        piece_t("Q", "black", 0),
        piece_t("R", "black", 0),
        piece_t("R", "black", 1),
        piece_t("R", "white", 0),
        piece_t("R", "white", 1),
        piece_t("B", "black", 0),
        piece_t("B", "black", 1),
        piece_t("B", "white", 0),
        piece_t("B", "white", 1),
        piece_t("N", "black", 0),
        piece_t("N", "black", 1),
        piece_t("N", "white", 0),
        piece_t("N", "white", 1),
        piece_t("P", "black", 0),
        piece_t("P", "black", 1),
        piece_t("P", "black", 2),
        piece_t("P", "black", 3),
        piece_t("P", "black", 4),
        piece_t("P", "black", 5),
        piece_t("P", "black", 6),
        piece_t("P", "black", 7),
        piece_t("P", "black", 8),
        piece_t("P", "white", 0),
        piece_t("P", "white", 1),
        piece_t("P", "white", 2),
        piece_t("P", "white", 3),
        piece_t("P", "white", 4),
        piece_t("P", "white", 5),
        piece_t("P", "white", 6),
        piece_t("P", "white", 7),
        piece_t("P", "white", 8)
    };
};

#endif