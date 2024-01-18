#include <iostream>

using Object = void*;
using child_callback_f = void(*)(Object);


class Child {
public:
    Object parent = nullptr;
    child_callback_f callback = nullptr;
    Child(void* parent, child_callback_f cbk) {
    }
};

class Parent {
public:
    Parent();
    void child_calback();
    static void child_calback(Object obj);

    Child* child;

};

int main() {

    Parent* parent1 = new Parent();
    Parent* parent2 = new Parent();

    Parent::child_calback(parent1);

    return 0;
}

Parent::Parent() {
    child = new Child(this, child_calback);
}

void Parent::child_calback() {
    std::cout << "child_calback" << '\n';
}

void Parent::child_calback(Object obj) {

    static_cast<Parent*>(obj)->child_calback();
}

