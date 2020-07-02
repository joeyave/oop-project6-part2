//
// Created by avelt on 4/23/2020.
//

#ifndef PROJECT6_PART2_SERVICEPROVIDER_H
#define PROJECT6_PART2_SERVICEPROVIDER_H

#include <fstream>
#include <pqxx/pqxx>
#include <iostream>

class ServiceProvider {
public:
    static pqxx::connection getConnection();
};


#endif //PROJECT6_PART2_SERVICEPROVIDER_H
