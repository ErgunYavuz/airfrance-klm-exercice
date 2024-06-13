#ifndef OND_HPP
#define OND_HPP

#include <iostream>
#include <set>
#include <fstream>

class OnD {
private:
    char* origin;
    char* destination;
    std::set<double> tarifs;

public:
    OnD(const char* origin, const char* destination, std::set<double> tarifs);

    char* getOrigin();
    char* getDest();
    std::set<double> getTarifs();

    void setOrigin(const char* org);
    void setDest(const char* dest);
    void setTarifs(std::set<double>& tar);

    double minTarifs();
    double maxTarifs();
    double moyTarifs();

    int exportToCSV(std::ofstream& outputFile);
    std::string toString();
};

#endif