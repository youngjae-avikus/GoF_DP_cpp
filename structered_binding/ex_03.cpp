// With the introduction of structured bindings, we can now obtain a reference to the tuple members using auto&:

#include <iostream>
#include <tuple>

int main()
{
    auto tuple = std::make_tuple(1, 'a', 2.3);

    // unpack the tuple into its individual components
    auto &[i, c, d] = tuple;

    std::cout << "i=" << i << ", c=" << c << ", d=" << d << '\n';

    // change the value of i inside the tuple
    i = 2;

    // show that the value inside the tuple has changed
    std::cout << "tuple<0>=" << std::get<0>(tuple) << '\n';

    return 0;
}