//
// Created by avelt on 4/23/2020.
//

#ifndef PROJECT6_PART2_ACCOUNT_H
#define PROJECT6_PART2_ACCOUNT_H


#include <string>
#include <ostream>
#include "ServiceProvider.h"


class Account {
public:
    Account();

    Account(int balance);

    Account(int id, int balance, int version);

    int getId() const;

    void setId(int id);

    int getBalance() const;

    void setBalance(int balance);

    int getVersion() const;

    void setVersion(int version);

private:
    int id;
    int balance;
    int version;
};

#endif //PROJECT6_PART2_ACCOUNT_H
