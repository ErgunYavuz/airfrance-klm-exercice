#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

#include "./lib/utils.hpp"
#include "./lib/ond.hpp"

using namespace std;


vector<string> split(string inputString, char delimiter){
    vector<string> elements;
    string item;
    istringstream ss(inputString);
    while(getline(ss, item, ';')){
        elements.push_back(item);
    }
    return elements;
}

bool isFileEmpty(string filename){
    ifstream read(filename);
	if(!read) return true;
    return read.peek() == EOF;
}

vector<OnD> csvToVector(string inputfile){

    ifstream inputFile(inputfile);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        exit (EXIT_FAILURE);
    }

    vector<OnD> vecOD;
    string line;
    
    getline(inputFile, line); //ignore first line of column names

    getline(inputFile, line);
    vector<string> elements = split(line, ';');
    set<double> tmpset;
    const char* prevOrigin = elements.at(0).c_str();
    const char* prevDestination = elements.at(1).c_str();    
    tmpset.insert(stod(elements.at(2)));

    while(getline(inputFile, line)){

        elements.clear();
        elements = split(line, ';');
        const char* origin = elements.at(0).c_str();
        const char* destination = elements.at(1).c_str();

        if(((strcmp(prevOrigin, origin) == 0) && (strcmp(prevDestination, destination) == 0)) ){
            tmpset.insert(stod(elements.at(2)));
        }

        else{
            vecOD.emplace_back(prevOrigin, prevDestination, tmpset);
            tmpset.clear();
            tmpset.insert(stod(elements.at(2)));
        }
        
        prevOrigin = origin;
        prevDestination = destination;
        
    }
    vecOD.emplace_back(prevOrigin, prevDestination, tmpset);
    return vecOD;
}



vector<OnD> csvToVector2(string inputfile){

    ifstream inputFile(inputfile);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        exit (EXIT_FAILURE);
    }

    vector<OnD> vecOD;
    string line;
    
    getline(inputFile, line); //ignore first line of column names

    getline(inputFile, line);
    vector<string> elements = split(line, ';');
    set<double> tmpset;
    const char* prevOrigin = elements.at(0).c_str();
    const char* prevDestination = elements.at(1).c_str();    
    tmpset.insert(stod(elements.at(2)));

    while(getline(inputFile, line)){

        elements.clear();
        elements = split(line, ';');
        const char* origin = elements.at(0).c_str();
        const char* destination = elements.at(1).c_str();

        if(((strcmp(prevOrigin, origin) == 0) && (strcmp(prevDestination, destination) == 0)) ){
            tmpset.insert(stod(elements.at(2)));
        }

        else{
            vecOD.emplace_back(prevOrigin, prevDestination, tmpset);
            tmpset.clear();
            tmpset.insert(stod(elements.at(2)));
        }
        
        prevOrigin = origin;
        prevDestination = destination;
        
    }
    vecOD.emplace_back(prevOrigin, prevDestination, tmpset);
    return vecOD;
}


int vectorToCSV(vector<OnD> vecOD, string filename){
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    if(isFileEmpty(filename)){
        outputFile << "Origine,Destination,TarifMinimum,TarifMaximum,TarifMoyen" << endl;
    }
    
    for(auto od : vecOD){
        od.exportToCSV(outputFile);
    }
    return 0;
}

