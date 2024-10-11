#include <vector>
#include <utility>
#include <iostream>

using namespace std;

static int simpleConstr;
static int copyConstr;
static int moveConstr;
class MyClass {
public:

    MyClass() {
        simpleConstr++;
    }
    MyClass(MyClass&& moved) {
        moveConstr++;
    }
    MyClass(const MyClass& moved) {
        copyConstr++;
    }


};
#define COUNT 999999

int main() {
        {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        MyClass t;
        for (int i = 0; i < COUNT;++i) {
            vec.push_back(t);
        }
        cout << "~res  copy" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }
        {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        MyClass t;
        vec.reserve(COUNT);
        for (int i = 0; i < COUNT;++i) {
            vec.push_back(t);
        }
        cout << " res  copy" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }
    {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        for (int i = 0; i < COUNT;++i) {
            vec.push_back(MyClass());
        }
        cout << "~res ~move" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }
    {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        for (int i = 0; i < COUNT;++i) {
            vec.push_back(move(MyClass()));
        }
        cout << "~res  move" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }
    {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        vec.reserve(COUNT);
        for (int i = 0; i < COUNT;++i) {
            vec.push_back(MyClass());
        }
        cout << " res ~move" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }
    {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        vec.reserve(COUNT);
        for (int i = 0; i < COUNT;++i) {
            vec.push_back(move(MyClass()));
        }
        cout << " res  move" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }

    {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        vec.reserve(COUNT);
        for (int i = 0; i < COUNT;++i) {
            vec.emplace_back();
        }
        cout << " res  empl" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }

        {
        simpleConstr = 0;
        copyConstr = 0;
        moveConstr = 0;
        vector<MyClass> vec;
        for (int i = 0; i < COUNT;++i) {
            vec.emplace_back();
        }
        cout << "~res  empl" << " : ";
        cout << simpleConstr << ' '
            << copyConstr << ' '
            << moveConstr << endl;
    }

    return 0;
}
