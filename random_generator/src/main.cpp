#include <fstream>
#include <random>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;



//длинна слова
#define MIN_WORD_LENTH 1
#define MAX_WORD_LENTH 100
#define WORD_COUNT 10000
#define FIRST_CHAR 97 // 'a'
#define LAST_CHAR 122 // 'z'
#define MIN_DOC_SIZE 1
#define MAX_DOC_SIZE 1000
#define DOC_COUNT 50000
vector<char> chars = { 'a','b' };


//1 сгенерировать длинну слова от 1 до 100

// сгенерировать слово взять буквы из массисива букв 


int main() {
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> word_lenth(MIN_WORD_LENTH, MAX_WORD_LENTH);
    uniform_int_distribution<> char_generator(FIRST_CHAR, LAST_CHAR);
    uniform_int_distribution<> doc_size_generator(MIN_DOC_SIZE, MAX_DOC_SIZE);
    stringstream word;

    ofstream output("output.txt");

    //генерируем 10000 слов
    int word_count = WORD_COUNT;
    vector<string> words;
    words.reserve(10000);
    while (word_count) { //генерируем документ
        int current_word_lenth = word_lenth(generator);
        while (current_word_lenth) { // генерируем слово
            char ch = char_generator(generator);
            word << ch;
            --current_word_lenth;
        }
        words.push_back(word.str());
        --word_count;
    }



    // int doc_count = DOC_COUNT;
    // while (doc_count) {

    //     --doc_count;
    // }

    return 0;
}

#if 0
int main() {
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(a, b);

    ofstream output("output.txt");
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
#endif