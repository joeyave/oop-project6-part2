//
// Created by avelt on 4/23/2020.
//

#ifndef PROJECT6_PART2_CAR_H
#define PROJECT6_PART2_CAR_H


#include <string>
#include <ostream>
#include "ServiceProvider.h"


class Car {
public:
    Car();

    int getId() const;

    void setId(int id);

    Car(const std::string& model, const std::string& color, int version);

    const std::string& getModel() const;

    void setModel(const std::string& model);

    const std::string& getColor() const;

    void setColor(const std::string& color);

    int getVersion() const;

    void setVersion(int version);

    friend std::ostream& operator<<(std::ostream& os, const Car& car);

private:
    int id;
    std::string model;
    std::string color;
    int version{};
};

#endif //PROJECT6_PART2_CAR_H
