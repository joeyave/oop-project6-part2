//
// Created by avelt on 4/23/2020.
//

#include "Car.h"

#include <utility>

Car::Car(const std::string& model, const std::string& color, int version) : model(model), color(color),
                                                                            version(version) {}

Car::Car() {}

const std::string& Car::getModel() const {
    return model;
}

void Car::setModel(const std::string& model) {
    Car::model = model;
}

const std::string& Car::getColor() const {
    return color;
}

void Car::setColor(const std::string& color) {
    Car::color = color;
}

int Car::getVersion() const {
    return version;
}

void Car::setVersion(int version) {
    Car::version = version;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "model: " << car.model << " color: " << car.color << " version: " << car.version;
    return os;
}

int Car::getId() const {
    return id;
}

void Car::setId(int id) {
    Car::id = id;
}
