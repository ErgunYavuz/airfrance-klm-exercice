#include <cstring>
#include <string>

#include "./lib/ond.hpp"


using namespace std;

OnD::OnD(const char* org, const char* dest, set<double> tar) {
    setOrigin(org);
    setDest(dest);
    setTarifs(tar);
}

char* OnD::getOrigin(){return origin;}
char* OnD::getDest(){return destination;} 
set<double> OnD::getTarifs(){return tarifs;}

void OnD::setOrigin(const char* org){
    origin = new char[sizeof(org)];
    strcpy(origin, org);
}
void OnD::setDest(const char* dest){
    destination = new char[sizeof(dest)];
    strcpy(destination, dest);
} 
void OnD::setTarifs(set<double> &tar){
    tarifs = tar;
}

double OnD::minTarifs(){
    return *tarifs.begin();
}

double OnD::maxTarifs(){
    return *tarifs.rbegin();;
}

double OnD::moyTarifs(){
    double sum = 0.0;
    for (auto itr : tarifs){
        sum += itr;
    }
    return sum/tarifs.size();
}

int OnD::exportToCSV(ofstream &outputFile){
    outputFile << getOrigin() << ',' << getDest() << ',' << minTarifs() << ',' << maxTarifs() << ',' << moyTarifs() << endl;
    return 1;
}

string OnD::toString(){
    string str = origin;
    str += destination;
    str += "\n";
    for (double tarif : tarifs){
        str.append(to_string(tarif)+", ");
    }
    return str;
}    
