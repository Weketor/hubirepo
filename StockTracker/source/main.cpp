//#include <memory>

#include <csv_handler.hh>
#include <iso646.h>
#include <string>

using namespace std;

int main(){
    CsvHandler current_csv;
    current_csv.readAll();
    current_csv.print();
    return 0;
}
