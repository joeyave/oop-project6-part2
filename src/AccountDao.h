//
// Created by avelt on 4/23/2020.
//

#ifndef PROJECT6_PART2_ACCOUNTDAO_H
#define PROJECT6_PART2_ACCOUNTDAO_H


#include "Account.h"
#include "ServiceProvider.h"

class AccountDao {
public:
    void insert(const Account& account);

    pqxx::result getAll();

    pqxx::row getById(int id);

    void update(const Account& account);

    void remove(const Account& account);
};


#endif //PROJECT6_PART2_ACCOUNTDAO_H
