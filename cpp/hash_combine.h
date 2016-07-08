#include <functional>
#include <string>
#include <tuple>
#include <utility>


template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}


namespace {

template <size_t n>
struct tuple_hash {
    template <typename... Types>
    static void combine(std::size_t& seed, const std::tuple<Types...>& tpl) {
        tuple_hash<n - 1>::combine(seed, tpl);
        hash_combine(seed, std::get<n>(tpl));
    }
};

template<>
struct tuple_hash<0> {
    template <typename... Types>
    static void combine(std::size_t& seed, const std::tuple<Types...>& tpl) {
        hash_combine(seed, std::get<0>(tpl));
    }
};

} // namespace anonymous


namespace std {

// pair hash
template <typename T1, typename T2>
struct hash<std::pair<T1, T2>> {
    auto operator()(const std::pair<T1, T2>& p) const {
        size_t seed = 0;
        hash_combine(seed, p.first);
        hash_combine(seed, p.second);
        return seed;
    }
};


// tuple hash
template<typename... Types>
struct hash<std::tuple<Types...>> {
    auto operator()(const std::tuple<Types...>& tpl) const {
        size_t seed = 0;
        tuple_hash<sizeof...(Types) - 1>::combine(seed, tpl);
        return seed;
    }
};

} // namespace std
