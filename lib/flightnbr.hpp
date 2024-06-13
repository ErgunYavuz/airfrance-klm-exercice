#ifndef FLIGHTNBR_HPP
#define FLIGHTNBR_HPP

#include <fstream>
#include "ond.hpp"

class FlightNbr {
private:
    const char* flightNumber;
    OnD* od;

public:
    FlightNbr(const char* num, OnD* o);

    void exportToFile(std::string filename);
};

#endif