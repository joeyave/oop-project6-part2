#include "src/ServiceProvider.h"
#include "src/Car.h"
#include "src/CarDao.h"
#include <fstream>
#include <iostream>
#include <pqxx/pqxx>

int main() {
    try {
        Car car1("McLaren P1", "yellow", 0);

        CarDao carDao;
        //carDao.insert(car1);
        auto cars = carDao.getAll();

        // Print table.
        for (const auto& row : cars) {
            for (const auto& col : row) {
                std::cout << col.c_str() << '\t';
            }
            std::cout << '\n';
        }
    }
    catch (std::exception const& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
