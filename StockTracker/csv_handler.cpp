#include "csv_handler.hh"

regex VALID_REGEX("[[:space:]]*[[:w:]]+[[:space:]]*:[[:space:]]*[[:w:]]+[[:space:]]*");
regex COMMENT_REGEX("[[:space:]]*#+.*");
smatch csv_line;

void CsvHandler::readAll(){
    cout << "Input file: ";
    string filename;
    getline(cin, filename);
    ifstream streamfile_(filename);   // Creates streamfile_
    if ( ! streamfile_ ){
        cout << "Error: Can't open the file" << endl;
        return;
    }

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
//            vector<const string> stock_propertiesV;  //  Same as a row
            tuple<double, double> company_properties(end_priceD, market_cap);
            stock_map_.at(company_name) = company_properties;
//            stock_properties.push_back(end_price);
        }

    }
    streamfile_.close();
    return;
}

MyMapType CsvHandler::returnTable(){
    return stock_map_;
}

void CsvHandler::print(){
    for (auto& key: stock_map_) {
        cout << key.first << ": ";
//        cout << key.second << '\n';
      }
}
