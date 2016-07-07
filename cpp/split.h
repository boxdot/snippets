#include <sstream>
#include <string>
#include <vector>


auto split(const std::string &s, char delim = ' ') {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.emplace_back(std::move(item));
        }
    }
    return elems;
}
