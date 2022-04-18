#include "DataHandler.h"

DataHandler::DataHandler(std::string name) {
	filename = name + ".csv";
}

void DataHandler::push(int n, float time) {
	nValues.push_back(n);
	times.push_back(time);
}

void DataHandler::write() {
    std::ofstream fh;
    if (nValues.size() != times.size()) {
        std::cout << "Data.write: dict mismatch!" << std::endl;
    }

    fh.open(filename);
    fh << "n,time\n";
    for (int i = 0; i < nValues.size(); i++) {
        fh << std::to_string(nValues.at(i)) << "," << std::to_string(times.at(i)) << "\n";
    }
    fh.close();
}