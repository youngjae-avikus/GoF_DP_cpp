#include <iostream>

struct Foo
{
    // unpack the struct into individual variables declared at the call site
    int i;
    char c;
    double d;
};

int main()
{
    Foo f{1, 'a', 2.3};

    // unpack the struct into individual variables declared at the call site
    auto &[i, c, d] = f;

    std::cout << "i=" << i << " c=" << c << " d=" << d << '\n';

    // change the member c
    c = 'b';

    // show the value changed in f
    std::cout << "f.c=" << f.c << '\n';

    return 0;
}