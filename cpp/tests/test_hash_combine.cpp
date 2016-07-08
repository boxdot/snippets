#include "../hash_combine.h"
#include <catch.hpp>
#include <string>
#include <unordered_map>


TEST_CASE("Hash combine smoke test", "[hash_combine]")
{
    size_t seed = 0;
    hash_combine(seed, 42);
    hash_combine(seed, 42.);
    hash_combine(seed, 42.f);
    hash_combine(seed, std::string("foobar"));
}

TEST_CASE("Pair hash smoke test", "[hash_combine]")
{
    std::unordered_map<std::pair<long, std::string>, int> mapping =
        { {{0, "Hello"}, 5}
        , {{1, "World"}, 5}
        };
}

TEST_CASE("Pair hash test", "[hash_combine]")
{
    auto p = std::make_pair(1, std::string("Hello, World!"));
    auto hash = std::hash<decltype(p)>{}(p);

    size_t seed = 0;
    hash_combine(seed, std::hash<int>{}(1));
    hash_combine(seed, std::hash<std::string>{}(std::string("Hello, World!")));

    REQUIRE(hash == seed);
}


TEST_CASE("Tuple hash smoke test", "[hash_combine]") {
    std::unordered_map<std::tuple<long, long, long>, long> mapping =
        { {{0, 1, 2}, 3}
        , {{1, 2, 3}, 6}
        , {{2, 3, 6}, 11}
        };
}

TEST_CASE("Tuple hash test", "[hash_combine]")
{
    auto tpl = std::make_tuple(1, 2, std::string("Hello, World!"), 42.);
    auto hash = std::hash<decltype(tpl)>{}(tpl);

    size_t seed = 0;
    hash_combine(seed, std::hash<int>{}(1));
    hash_combine(seed, std::hash<int>{}(2));
    hash_combine(seed, std::hash<std::string>{}(std::string("Hello, World!")));
    hash_combine(seed, std::hash<double>{}(42.));

    REQUIRE(hash == seed);
}
