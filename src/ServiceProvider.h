//
// Created by avelt on 4/23/2020.
//

#ifndef PROJECT6_PART2_SERVICEPROVIDER_H
#define PROJECT6_PART2_SERVICEPROVIDER_H


#include <fstream>
#include <pqxx/pqxx>
#include <iostream>
#include "../include/nlohmann/json.hpp"

using json = nlohmann::json;

class ServiceProvider {
public:
    static json read();

    static void write(json db);

    static pqxx::connection getConnection();
};


#endif //PROJECT6_PART2_SERVICEPROVIDER_H
