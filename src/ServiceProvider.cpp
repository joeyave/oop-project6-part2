//
// Created by avelt on 4/23/2020.
//

#include "ServiceProvider.h"

[[nodiscard]] json ServiceProvider::read() {
    std::ifstream ifstream("data/db.json");
    json db;
    ifstream >> db;
    return db;
}

void ServiceProvider::write(json db) {
    std::ofstream ofstream("data/db.json");
    ofstream << db;
}

pqxx::connection ServiceProvider::getConnection() {
    pqxx::connection conn("dbname=postgres host=localhost user=postgres password=1234");
    return conn;
}
