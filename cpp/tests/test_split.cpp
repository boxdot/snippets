#include "../split.h"
#include <catch.hpp>

TEST_CASE("Simple split", "[split]")
{
    auto res = split("Hello, World!");
    REQUIRE(res == (std::vector<std::string>{"Hello,", "World!"}));
}
