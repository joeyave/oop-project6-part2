//
// Created by avelt on 4/23/2020.
//

#include "ServiceProvider.h"

pqxx::connection ServiceProvider::getConnection() {
    pqxx::connection conn("dbname=postgres host=localhost user=postgres password=root");
    return conn;
}
