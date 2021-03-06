#ifndef CSV_HANDLER_HH
#define CSV_HANDLER_HH

#include <ios>
#include <iso646.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <map>
#include <tuple>


using namespace std;
using MyMapType  = map<const string, tuple<double, double>>;

class CsvHandler
{
public:
    void readAll();
    MyMapType returnTable();
    void print();
    void searchByName();
private:
    ifstream streamfile_;
    MyMapType stock_map_;
};

#endif // CSV_HANDLER_HH
