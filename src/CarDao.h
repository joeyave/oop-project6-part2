//
// Created by avelt on 4/23/2020.
//

#ifndef PROJECT6_PART2_CARDAO_H
#define PROJECT6_PART2_CARDAO_H


#include "Car.h"
#include "ServiceProvider.h"

class CarDao {
public:
    void insert(const Car& car);

    pqxx::result getAll();

    void update(const Car& car);

    void deleteById(int id);
};


#endif //PROJECT6_PART2_CARDAO_H
