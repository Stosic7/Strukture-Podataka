#include "OpenScatterTable.h"
#include <string>

bool addVehicle(OpenScatterTable& table, const std::string& chassisNumber, const std::string& make, const std::string& model, int year) {
    std::string key = chassisNumber;
    ScatterObject vehicle(key.c_str());
    vehicle.setAttributes(make, model, year);

    return table.insert(vehicle);
}

void setAttributes(const std::string& make, const std::string& model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
}
