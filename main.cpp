
#include <vector>

#include "./lib/ond.hpp"
#include "./lib/utils.hpp"
#include "./lib/flightnbr.hpp"

using namespace std;

int main(){
     
    vector<OnD> vecOD = csvToVector("./input/OrigineDestinationTarif.csv");
    vectorToCSV(vecOD, "./output/testplsworkimloosingmysanitwhythefuckarethevaluesthesame.csv");
     // Example FlightNbr usage
    OnD* sampleOD = &vecOD[0];
    FlightNbr flight("ABC123", sampleOD);
    flight.exportToFile("./output/flights.csv");
    //cout<<vecOD.at(0).getTarifs().size()<<endl;
}

