#include <iostream>
#include <sstream>

using namespace std;

struct St {
    int a;
    int b;
    int c;
};

St Read(istream& in_stream = cin) {

    St st;
    in_stream >> st.a >> st.b >> st.c;

    return st;
}

int main() {

    istringstream ss("1 2 3");
    St st = Read(ss);
    cout << st.a << ' ' << st.b << ' ' << st.c << '\n';
    return 0;
}