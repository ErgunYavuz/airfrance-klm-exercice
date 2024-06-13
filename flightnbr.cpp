#include <iostream>

#include "./lib/flightnbr.hpp"
#include "./lib/utils.hpp"

FlightNbr::FlightNbr(const char* num, OnD* o) : flightNumber(num), od(o) {}

void FlightNbr::exportToFile(std::string filename) {
    std::ofstream outputFile(filename, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    if (isFileEmpty(filename)) {
        outputFile << "NumeroDeVol,Origine,Destination,MinimumFare,MaximumFare,MoyenneFare" << std::endl;
    }

    outputFile << flightNumber << ',' << od->getOrigin() << ',' << od->getDest() << ','
               << od->minTarifs() << ',' << od->maxTarifs() << ',' << od->moyTarifs() << std::endl;
}