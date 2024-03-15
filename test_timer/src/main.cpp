#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>



void myFunction() {
    std::cout << "Функция вызвана каждую секунду!" << std::endl;
}
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    while (true) {
        myFunction();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
