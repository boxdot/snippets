#include <tuple>


namespace {

template <size_t... n>
struct ct_integers_list {
    template <size_t m>
    struct push_back
    {
        using type = ct_integers_list<n..., m>;
    };
};

template <size_t max>
struct ct_iota_1
{
    using type = typename ct_iota_1<max-1>::type::template push_back<max>::type;
};

template <>
struct ct_iota_1<0>
{
    using type = ct_integers_list<>;
};

} // namespace anonymous



template <size_t... indices, typename Tuple>
auto subset(const Tuple& tpl, ct_integers_list<indices...>)
    -> decltype(std::make_tuple(std::get<indices>(tpl)...))
{
    return std::make_tuple(std::get<indices>(tpl)...);
}

template <typename Head, typename... Tail>
std::tuple<Tail...> tail(const std::tuple<Head, Tail...>& tpl)
{
    return subset(tpl, typename ct_iota_1<sizeof...(Tail)>::type());
}
