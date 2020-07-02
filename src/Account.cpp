//
// Created by avelt on 4/23/2020.
//

#include "Account.h"

Account::Account() {}

int Account::getId() const {
    return id;
}

void Account::setId(int id) {
    Account::id = id;
}

int Account::getBalance() const {
    return balance;
}

void Account::setBalance(int balance) {
    Account::balance = balance;
}

int Account::getVersion() const {
    return version;
}

void Account::setVersion(int version) {
    Account::version = version;
}

Account::Account(int balance) : balance(balance), version(0) {}

Account::Account(int id, int balance, int version) : id(id), balance(balance), version(version) {}
