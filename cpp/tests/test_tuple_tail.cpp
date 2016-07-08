#include "../tuple_tail.h"
#include <catch.hpp>


TEST_CASE("Compile time integers", "[ct_integers]") {
    ct_integers_list<1, 2, 3> x;
}

TEST_CASE("Tuple subset", "[tuple]") {
    ct_integers_list<1, 2, 3> indices;
    std::tuple<int, int, int, int> t = {1, 2, 3, 4};
    auto ts = subset(t, indices);
    REQUIRE(std::get<0>(ts) == 2);
    REQUIRE(std::get<1>(ts) == 3);
    REQUIRE(std::get<2>(ts) == 4);
}

TEST_CASE("Tuple tail", "[tuple]") {
    ct_integers_list<1, 2, 3> indices;
    std::tuple<int, int, int, int> t = {1, 2, 3, 4};
    auto ts = tail(t);
    REQUIRE(std::get<0>(ts) == 2);
    REQUIRE(std::get<1>(ts) == 3);
    REQUIRE(std::get<2>(ts) == 4);
}
