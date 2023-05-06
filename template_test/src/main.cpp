#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <deque>


using namespace std;

// шаблон пара
template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

// шаблон IteratorRange
template<typename Iterator>
class IteratorRange {
private:
    Iterator first, last;

public:
    IteratorRange(Iterator f, Iterator l)
        : first(f)
        , last(l) {

    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }
};


template <typename Container>
IteratorRange<typename Container::iterator> Head(Container& v, size_t top) {
    return IteratorRange{
        v.begin(), next(v.begin(), min(top,v.size()))
    };
}

template <typename T>
size_t RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}

//пораждающая функция
template<typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end) {
    return IteratorRange<Iterator>{begin, end};
}


int main() {
    {
        Pair <string, int> si;
        si.first = "Hello";
        si.second = 5;

        Pair <bool, char> bc;
        bc.first = true;
        bc.second = 'z';
    }

    vector<int> v = { 1,2,3,4,5 };
    for (int x : Head(v, 3)) {
        cout << x << " ";
    }
    cout << endl;
    cout << RangeSize(Head(v, 3));
    cout << endl;

    {
        auto second_half = MakeRange(v.begin() + v.size() / 2, v.end());
        for (auto x : second_half) {
            cout << x << ' ';
        }
        cout << endl;
    }
    {
        IteratorRange second_half(v.begin() + v.size() / 2, v.end());
        for (auto x : second_half) {
            cout << x << ' ';
        }
        cout << endl;
    }
    {
        set<int> nums = { 5,7,4,12,4,9,4 };
        for (int x : Head(nums, 3)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    {
        const deque<int> nums2 = { 5,7,4,12,4,9,4 };
        for (int x : Head(nums2, 3)) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
