#include "piece.hpp"
#include "config.hpp"
#include <iostream>

piece::piece(const piece_t& t, std::pair<int, int> p)
{
    if (!config::PIECES.contains(t))
        throw unexpected_type("invalid type_t");
    if(position.first < 0 || position.first > 8 || position.second < 0 || position.second > 8)
        throw unexpected_value("piece's position array contains an invalid value");

    position = p;
    type = &t;
}

piece_t piece::get_type() const
{
    return *type;
}
std::pair<int, int> piece::get_position() const
{
    return position;
}

std::ostream& operator<<(std::ostream& os, const piece& p)
{
    std::pair<int, int> tmp = p.get_position();
    os << "type: " << p.get_type() << ".\nposition: (" << tmp.first << ", " << tmp.second << ")";
    return os;
}