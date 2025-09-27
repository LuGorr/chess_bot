#include <utility>
#include "utils.hpp"
#ifndef PIECE_HPP
#define PIECE_HPP
class piece
{
    public:
        piece(const piece_t& type, std::pair<int, int> position);
        piece_t get_type() const;
        std::pair<int, int> get_position() const;
    private:
        const piece_t* type;
        std::pair<int, int> position;
};

std::ostream& operator<<(std::ostream& os, const piece& p);

#endif