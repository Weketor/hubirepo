#include "csv_handler.hh"

regex VALID_REGEX("([[:space:]]*[[:w:]]+[[:space:]]*)+(,\"[[:digit:]]+[KMB%]\")");
regex COMMENT_REGEX("[[:space:]]*#+*.*");
smatch csv_line;

void CsvHandler::readAll(){
    cout << "Input file: ";
    string filename;
    getline(cin, filename);
    ifstream streamfile_;
    streamfile_.open("..\\imports\\" + filename);
    if ( ! streamfile_.is_open()){
        cout << "Error: Can't open the file" << endl;
        streamfile_.close();
        return;
    }
    cout << "open success" << endl;
    string row_string;
    int csv_rownum = 0;
    while (getline(streamfile_, row_string)){
        ++csv_rownum;
        if (regex_match(row_string, COMMENT_REGEX))
            continue;
        else if (row_string == "")
            continue;
        else if (regex_match(row_string, VALID_REGEX)){    // Useful row
            const string company_name = csv_line.str(1);
//            const string end_price = csv_line.str(2);
            double end_priceD = stod(csv_line.str(2));
            double market_cap = stod(csv_line.str(3));
            tuple<double, double> company_properties(end_priceD, market_cap);
            stock_map_.insert({company_name, company_properties});
            cout << "Read success" << endl;
        }
        else{
            cout << "Regex not valid" << endl;
        }
    }
    streamfile_.close();
    return;
}

MyMapType CsvHandler::returnTable(){
    return stock_map_;
}

void CsvHandler::print(){
    for (auto item: stock_map_) {
        cout << item.first << ": " << endl;
        cout << get<0>(item.second) << '\n';
    }
}

void CsvHandler::searchByName()
{

}
