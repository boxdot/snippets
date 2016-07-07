// Convenience functions returning iterators to keys and values of an
// associative container.

// Convenience functions returning iterators to keys and values of an
// associative container.

namespace {

template <typename Iterator>
class IteratorBase {
public:
    using difference_type = typename Iterator::difference_type;
    using iterator_category = typename Iterator::iterator_category;

    explicit IteratorBase(Iterator it) : it_(it) {}
    auto& operator++() { ++it_; return *this; }
    auto operator==(IteratorBase other) { return it_ == other.it_; }
    auto operator!=(IteratorBase other) { return !(*this == other); }

protected:
    Iterator it_;
};


template <typename Iterator>
class KeysIterator : public IteratorBase<Iterator> {
public:
    using value_type = typename Iterator::value_type::first_type;
    using pointer = value_type*;
    using reference = value_type&;

    using IteratorBase<Iterator>::IteratorBase;
    auto operator*() { return IteratorBase<Iterator>::it_->first; }
};

template <typename Iterator>
class ValuesIterator : public IteratorBase<Iterator> {
public:
    using value_type = typename Iterator::value_type::second_type;
    using pointer = value_type*;
    using reference = value_type&;

    using IteratorBase<Iterator>::IteratorBase;
    auto operator*() { return IteratorBase<Iterator>::it_->second; }
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
