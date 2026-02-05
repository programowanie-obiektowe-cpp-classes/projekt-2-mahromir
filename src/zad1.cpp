#include <print>
#include <ranges>
#include <string>
#include <vector>
#include "catch.hpp"

auto parseInput(const std::string& input)
{
    return input | std::views::split('\n') | std::views::transform([](auto&& line) -> int {
               const bool right     = line.front() == 'R';
               const auto num_range = line | std::views::drop(1);
               const int  num       = std::stoi(std::string{num_range.data(), num_range.size()});
               return right ? num : -num;
           }) |
           std::ranges::to< std::vector >(); // na wykladzie zapomnialem po prostu #include <vector>
}

int day1a(const std::vector< int >& input_parsed)
{
    int dial  = 50;
    int count = 0;
    for (int turn : input_parsed)
    {
        dial += turn;
        count += dial % 100 == 0;
    }
    return count;
}

int day1b(const std::vector< int >& input_parsed)
{
    int dial  = 50;
    int count = 0;
    for (int turn : input_parsed)
    {
        count += std::abs(turn / 100); // liczba pelnych obrotow
        turn                  = turn % 100;
        const bool not_start0 = dial != 0;
        dial += turn;
        count += not_start0 and dial != std::clamp(dial, 1, 99); // jeżeli start w 0 to nie ma click
        if (dial > 99)
            dial -= 100;
        if (dial < 0)
            dial += 100;
    }
    return count;
}

TEST_CASE("Day1 - 2025", "[zad1]")
{
    const std::string input = R"(L68
L30
R48
L5
R60
L55
L1
L99
R14
L82)";
    const auto        turns = parseInput(input);
    std::println("{}", day1a(turns));
    std::println("{}", day1b(turns));
}