//
// Created by avelt on 4/23/2020.
//

#include "CarDao.h"

void CarDao::insert(const Car& car) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "insert",
            "INSERT INTO cars (model, color) "
            "VALUES ($1, $2)"
    );

    transaction.exec_prepared("insert", car.getModel(), car.getColor());
    transaction.commit();
}

pqxx::result CarDao::getAll() {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    auto result = transaction.exec("SELECT * FROM cars");

    return result;
}

void CarDao::update(const Car& car) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "update",
            "UPDATE cars "
            "SET model = $1, color = $2, version = $3 "
            "WHERE id = $4"
    );

    transaction.exec_prepared("update",
                              car.getModel(),
                              car.getColor(),
                              car.getVersion(),
                              car.getId()
    );

    transaction.commit();
}

void CarDao::deleteById(int id) {
    auto connection = ServiceProvider::getConnection();
    pqxx::work transaction{connection};

    connection.prepare(
            "delete_by_id",
            "DELETE FROM cars WHERE id = $1"
    );

    transaction.exec_prepared("delete_by_id", id);
    transaction.commit();
}
