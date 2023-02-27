#include <iostream>
#include <map>

std::map<std::string, int> get_map()
{
    return {
        {"hello", 1},
        {"world", 2},
        {"it's", 3},
        {"me", 4},
    };
}

int main()
{
    for (auto &&[k, v] : get_map())
        std::cout << "k=" << k << " v=" << v << '\n';

    for (auto &[k, v] : get_map())
    {
        v = 100;
        std::cout << "k=" << k << " v=" << v << '\n';
    }
    return 0;
}