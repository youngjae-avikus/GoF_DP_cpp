#include <tuple>
#include <iostream>

std::tuple<int, int> divide(int dividend, int divisor)
{
    return {dividend / divisor, dividend % divisor};
}

int main()
{
    auto [quotient, remainder] = divide(14, 3);
    std::cout << quotient << ',' << remainder << std::endl;
}