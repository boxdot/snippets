#include "../hash_combine.h"
#include <catch.hpp>
#include <string>


TEST_CASE("Hash combine smoke test", "[hash_combine]")
{
    size_t seed = 0;
    hash_combine(seed, 42);
    hash_combine(seed, 42.);
    hash_combine(seed, 42.f);
    hash_combine(seed, std::string("foobar"));
}
