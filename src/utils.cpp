#include "utils.hpp"
#include "config.hpp"
#include <iostream>

piece_t::piece_t(std::string t, std::string c, int n) : 
    type(piece_t::check_type(t)), 
    colour(piece_t::check_colour(c)),
    number(piece_t::check_number(n)) {};

std::string piece_t::check_type(std::string& type) const
{
    if (!config::TYPES.contains(type))
        throw unexpected_type("invalid type for piece_t instantiation -> " + type);
    return type;
}

std::string piece_t::check_colour(std::string& colour) const
{
    if (colour != "black" && colour != "white")
        throw unexpected_value("invalid colour for piece_t instantiatio -> " + colour);
    return colour;
}

int piece_t::check_number(int& number) const
{
    if (number < 0 && ((type == "P" && number > 8) || (type != "P" && number > 1) || ((type=="K" || type=="Q") && number != 0)))
        throw unexpected_value("invalid number for type_t instantiation -> " + number);
    return number;
}

std::string piece_t::get_type() const
{
    return type;
}

std::string piece_t::get_colour() const
{
    return colour;
}

int piece_t::get_number() const
{
    return number;
}

std::tuple<std::string, std::string, int> piece_t::get_all() const
{
    return std::tuple<std::string, std::string, int>(type, colour, number);
}

size_t piece_t::hash_fn::operator()(const piece_t& p) const
{
    size_t type_hash = std::hash<std::string>()(p.get_type());
    size_t colour_hash = std::hash<std::string>()(p.get_colour());
    size_t number_hash = std::hash<int>()(p.get_number());
    return type_hash ^ colour_hash ^ number_hash;
}

bool piece_t::operator<(const piece_t& t) const
{
    return (type < t.get_type()) && 
            (colour < t.get_colour()) &&
            (number < t.get_number());
}

bool piece_t::operator==(const piece_t& t) const
{
    return (type == t.get_type()) && 
            (colour == t.get_colour()) &&
            (number == t.get_number());
}

std::ostream& operator<<(std::ostream& os, const piece_t& t)
{
    os << t.get_type() << ", " << t.get_colour() << ", " << t.get_number();
    return os;
}