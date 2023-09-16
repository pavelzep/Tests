#include <fstream>
#include <random>

const long long int a = -999999999;
const long long int b = 999999999;

int q1 = 50000;
int q2 = 50000;

int main() {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(a, b);

    std::ofstream output("output.txt");

    output << q1 + q2 << '\n';

    while (q1) {
        output << "ADD "
            << distribution(generator) << ' '
            << distribution(generator) << '\n';
        --q1;
    }

    while (q2) {

        output << "GO "
            << distribution(generator) << ' '
            << distribution(generator) << '\n';
        --q2;
    }

    return 0;
}