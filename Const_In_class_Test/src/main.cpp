#include <iostream>
#define FOO 5
#define BAR 3
class Test {
public:
    const int baz = foo * bar;
    const int foo = FOO;
    const int bar = BAR;
};
int main() {
    Test t;
    std::cout << t.foo << " " << t.bar << " " << t.baz << std::endl;
    return 0;
}