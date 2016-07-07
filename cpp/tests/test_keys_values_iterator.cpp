#include "../keys_values_iterator.h"

#include <catch.hpp>
#include <unordered_map>
#include <numeric>


auto test_container() {
    std::unordered_map<int, int> map;
    for (int i = 0; i < 10; ++i) {
        map[i] = i*i;
    }
    return map;
}


TEST_CASE("Test keys iterator", "[keys]")
{
    auto map = test_container();
    int sum = 0;
    for (auto i : keys(map)) {
        sum += i;
    }
    REQUIRE(sum == 45);
}

TEST_CASE("Test keys iterator with accumulate", "[keys]")
{
    auto map = test_container();
    int sum = std::accumulate(keys(map).begin(), keys(map).end(), 0);
    REQUIRE(sum == 45);
}

TEST_CASE("Test keys iterator with range constructor", "[keys]")
{
    auto map = test_container();
    std::vector<int> v(keys(map).begin(), keys(map).end());
    std::sort(v.begin(), v.end());
    int i = 0;
    for (auto x : v) {
        REQUIRE(x == i);
        i++;
    }
}

TEST_CASE("Test values iterator", "[values]")
{
    auto map = test_container();
    int sum = 0;
    for (auto i : values(map)) {
        sum += i;
    }
    REQUIRE(sum == 285);
}

TEST_CASE("Test values iterator with accumulate", "[values]")
{
    auto map = test_container();
    int sum = std::accumulate(values(map).begin(), values(map).end(), 0);
    REQUIRE(sum == 285);
}

TEST_CASE("Test values iterator with range constructor", "[values]")
{
    auto map = test_container();
    std::vector<int> v(values(map).begin(), values(map).end());
    std::sort(v.begin(), v.end());
    int i = 0;
    for (auto x : v) {
        REQUIRE(x == i*i);
        i++;
    }
}
