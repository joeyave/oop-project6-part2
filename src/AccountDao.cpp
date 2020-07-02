//
// Created by avelt on 4/23/2020.
//

#include "AccountDao.h"

void AccountDao::insert(const Account& account) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "insert",
            "INSERT INTO accounts (balance, version) "
            "VALUES ($1, $2)"
    );

    transaction.exec_prepared("insert",
                              account.getBalance(),
                              account.getVersion());
    transaction.commit();
}

pqxx::result AccountDao::getAll() {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    auto result = transaction.exec("SELECT * FROM accounts");

    return result;
}

pqxx::row AccountDao::getById(int id) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "get_by_id",
            "SELECT * FROM accounts "
            "WHERE id = $1"
    );

    return transaction.exec_prepared1("get_by_id", id);
}

void AccountDao::update(const Account& account) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "update",
            "UPDATE accounts "
            "SET balance = $1, version = version + 1 "
            "WHERE id = $2 AND version = $3"
    );

    transaction.exec_prepared("update",
                              account.getBalance(),
                              account.getId(),
                              account.getVersion()
    );

    transaction.commit();
}

void AccountDao::remove(const Account& account) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "delete_by_id",
            "DELETE FROM accounts "
            "WHERE id = $1 AND version = $2"
    );

    transaction.exec_prepared("delete_by_id",
                              account.getId(),
                              account.getVersion());
    transaction.commit();
}

