#include <future>
#include <iostream>
#include "synchronized.h"

using namespace std;
#if 0
struct Account {
    int balance = 0;
    bool Spend(int value) {
        if (value <= balance) {
            balance -= value;
            return true;
        }
        return false;
    };
};

int SpendMoney(Synchronized<Account>& account) {
    int total_spent = 0;
    for (size_t i = 0; i < 100'000; ++i) {
        if (account.GetAccess().ref_to_value.Spend(1)) {
            ++total_spent;
        }
    }
    return total_spent;
}

int main() {
    Synchronized<Account> family_account;
    family_account.GetAccess().ref_to_value.balance = 100'000;

    auto husband = async(SpendMoney, ref(family_account));
    auto wife = async(SpendMoney, ref(family_account));
    auto son = async(SpendMoney, ref(family_account));
    auto daughter = async(SpendMoney, ref(family_account));

    cout << "husband: " << husband.get() << endl
        << "wife: " << wife.get() << endl
        << "son: " << son.get() << endl
        << "daughter: " << daughter.get() << endl;
    return 0;
}
#endif
#if 0
struct Account {
    int balance = 0;
    mutex m;
    bool Spend(int value) {
        lock_guard <mutex > g(m);
        if (value <= balance) {
            balance -= value;
            return true;
        }
        return false;
    };
};

int SpendMoney(Account& account) {
    int total_spent = 0;
    for (size_t i = 0; i < 100'000; ++i) {
        if (account.Spend(1)) {
            ++total_spent;
        }
    }
    return total_spent;
}

int main() {
    Account family_account{ 100000 };
    auto husband = async(SpendMoney, ref(family_account));
    auto wife = async(SpendMoney, ref(family_account));
    auto son = async(SpendMoney, ref(family_account));
    auto daughter = async(SpendMoney, ref(family_account));
    cout << "husband: " << husband.get() << endl
        << "wife: " << wife.get() << endl
        << "son: " << son.get() << endl
        << "daughter: " << daughter.get() << endl;

    return 0;
}

#endif

struct Account {
    Account(int value) {
        balance.GetAccess().ref_to_value = value;
    }
    
    bool Spend(int value) {

        if (value <= balance.GetAccess().ref_to_value) {
            balance.GetAccess().ref_to_value -= value;
            return true;
        }
        return false;
    };
private:
    Synchronized<int> balance;
};

int SpendMoney(Account& account) {
    int total_spent = 0;
    for (size_t i = 0; i < 100'000; ++i) {
        if (account.Spend(1)) {
            ++total_spent;
        }
    }
    return total_spent;
}

int main() {
    Account family_account{ 100000 };
    auto husband = async(SpendMoney, ref(family_account));
    auto wife = async(SpendMoney, ref(family_account));
    auto son = async(SpendMoney, ref(family_account));
    auto daughter = async(SpendMoney, ref(family_account));
    cout << "husband: " << husband.get() << endl
        << "wife: " << wife.get() << endl
        << "son: " << son.get() << endl
        << "daughter: " << daughter.get() << endl;

    return 0;
}