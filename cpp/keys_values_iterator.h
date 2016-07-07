// Convenience functions returning iterators to keys and values of an
// associative container.

#include <unordered_map>
#include <vector>


namespace {

template <typename Iterator>
class PairIterator {
public:
    explicit PairIterator(Iterator it) : it_(it) {}
    auto& operator++() { ++it_; return *this; }
    auto operator==(PairIterator other) { return it_ == other.it_; }
    auto operator!=(PairIterator other) { return !(*this == other); }

protected:
    Iterator it_;
};


template <typename Iterator>
class KeysIterator : public PairIterator<Iterator> {
public:
    explicit KeysIterator(Iterator it) : PairIterator<Iterator>(it) {}
    auto operator*() {
        return PairIterator<Iterator>::it_->first;
    }
};

template <typename Iterator>
class ValuesIterator : public PairIterator<Iterator> {
public:
    using PairIterator<Iterator>::PairIterator;
    auto operator*() {
        return PairIterator<Iterator>::it_->second;
    }
};

template <typename Container, template<typename T> class WrapperIterator>
struct IteratorWrapper {
    using Iterator = typename Container::const_iterator;
    explicit IteratorWrapper(Container& c) : c_(c) {}
    auto begin() { return WrapperIterator<Iterator>{c_.begin()}; }
    auto end() { return WrapperIterator<Iterator>{c_.end()}; }

private:
    Container& c_;
};

} // namespace anonymous


template <typename Container>
auto keys(Container& c) {
    return IteratorWrapper<Container, KeysIterator>(c);
}

template <typename Container>
auto values(Container& c) {
    return IteratorWrapper<Container, ValuesIterator>(c);
}
