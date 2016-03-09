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

void CSVReader::InputData() {
    std::string newline;
    std::ifstream file ("C:\\Users\\dan\\Documents\\AAIS\\MLPNetwork\\FresnoDataCOC102.csv");
    dataEntry theInputData;
    while(std::getline(file, newline)) {
        std::stringstream lineStream(newline);
        std::string singleValue;
        
        while(std::getline(lineStream, singleValue, ',')) {
            int i = 0;
            theInputData[i] = singleValue;
        }
    }
}