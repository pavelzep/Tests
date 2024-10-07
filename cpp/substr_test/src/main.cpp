#include <string>
#include <string_view>
#include <iostream>
using namespace std;

int main() {

    const string substr = "yangle";
    const string s = "this new yangle service really rocks\n";


    string_view str = s;
    string_view result;
    size_t pos = 0;
    const size_t pos_end = str.npos;
    while (true) {
        size_t space = str.find(' ', pos);
        result = space == pos_end ? str.substr(pos) : str.substr(pos, space - pos);
        if (result == substr) {
            cout << 11111;
        }

        if (space == pos_end) {
            break;
        } else {
            pos = space + 1;
        }

    }



    return 0;

}