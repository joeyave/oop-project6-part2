#include "src/Account.h"
#include "src/AccountDao.h"
#include <fstream>
#include <iostream>

int main() {
    try {
        AccountDao alice;
        auto aliceTransaction = alice.getById(1);
        Account aliceAccount(aliceTransaction[0].as<int>(),
                             aliceTransaction[1].as<int>(),
                             aliceTransaction[2].as<int>());
        aliceAccount.setBalance(aliceAccount.getBalance() - 20);

        AccountDao bob;
        auto bobTransaction = bob.getById(1);
        Account bobAccount(bobTransaction[0].as<int>(),
                           bobTransaction[1].as<int>(),
                           bobTransaction[2].as<int>());
        bobAccount.setBalance(bobAccount.getBalance() - 40);

        bob.update(bobAccount);
        alice.update(aliceAccount);
    }
    catch (std::exception const& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
