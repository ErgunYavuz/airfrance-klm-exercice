#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
using namespace std;

class OnD;

vector<string> split(string inputString, char delimiter);
bool isFileEmpty(string filename);
vector<OnD> csvToVector(string inputfile);
int vectorToCSV(vector<OnD> vecOD, string filename);

#endif