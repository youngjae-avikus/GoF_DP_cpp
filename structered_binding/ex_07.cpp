#include <tuple>
#include <iostream>

auto divide(int dividend, int divisor)
{
    struct Result
    {
        int quotient;
        int remainder;
    };
    return Result{dividend / divisor, dividend % divisor};
}

int main()
{
    auto [quotient, remainder] = divide(14, 3);
    std::cout << quotient << ',' << remainder << std::endl;
}