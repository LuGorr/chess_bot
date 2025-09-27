#include <tuple>
#include <string>
#include <stdexcept>
#ifndef UTILS_HPP
#define UTILS_HPP

class piece_t
{
    public:
        piece_t(std::string type, std::string colour, int number);
        std::string get_type() const;
        std::string get_colour() const;
        int get_number() const;
        std::tuple<std::string, std::string, int> get_all() const;
        bool operator==(const piece_t& t) const;
        bool operator<(const piece_t& t) const;
        struct hash_fn
        {
            size_t operator()(const piece_t& p) const;
        };
    private:
        std::string check_type(std::string & t) const;
        std::string check_colour(std::string & c) const;
        int check_number(int & n) const;
        std::string const type;
        std::string const colour;
        int const number;
};

std::ostream& operator<<(std::ostream& os, const piece_t& t);

class unexpected_type : public std::runtime_error
{
    public:
    explicit unexpected_type(const std::string& message)
        : std::runtime_error(message) {}
};

class unexpected_value : public std::runtime_error
{
    public:
    explicit unexpected_value(const std::string& message)
        : std::runtime_error(message) {}
};

#endif