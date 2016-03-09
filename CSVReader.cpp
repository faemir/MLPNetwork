#include "CSVReader.h"

CSVReader::CSVReader()
{
}

CSVReader::~CSVReader()
{
}

bool CSVReader::is_empty(std::ifstream& pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void CSVReader::InputData(std::vector<dataEntry> *startingData) {
    std::string newline;
    std::ifstream file ("C:\\Users\\dan\\Documents\\AAIS\\MLPNetwork\\FresnoDataCOC102.csv");

    while(std::getline(file, newline)) {
        std::stringstream lineStream(newline);
        std::string singleValue;
        std::vector<std::string> tempList;
        dataEntry singleDataLine;
        while(std::getline(lineStream, singleValue, ',')) {
            tempList.push_back(singleValue);
        }
        singleDataLine.date = tempList[0];
        singleDataLine.temp = std::atof(tempList[1].c_str());
        singleDataLine.wind = std::atof(tempList[2].c_str());
        singleDataLine.rad = std::atof(tempList[3].c_str());
        singleDataLine.airp = std::atof(tempList[4].c_str());
        singleDataLine.hum = std::atoi(tempList[5].c_str());
        singleDataLine.evap = std::atof(tempList[6].c_str());
        startingData->push_back(singleDataLine);
    }
}