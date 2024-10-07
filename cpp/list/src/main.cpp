#include <list>
#include <numeric>



using namespace std;

int main() {

    list<int> l(10);
    iota(begin(l), end(l), 0);
    auto it = l.begin();
    // size_t N = 15;
    // for (size_t i = 0; i < N; ++i) {
    //     advance(it, 1);
    // }

    // int v = *it;
    it = next(it, 10);

    int v = *(it);


    return 0;
}
