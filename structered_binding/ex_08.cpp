// ref (Vector with structured binding)
/// https://stackoverflow.com/questions/51077383/does-structured-binding-work-with-stdvector

#include <iostream>
#include <array>

int main()
{
    std::array<int, 6> v{1, 2, 3, 4, 5, 6};
    auto [a, b, c, d, e, f] = v;
    std::cout << a << std::endl;

    return 0;
}