#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <cstdlib>

struct dataEntry {
    std::string date;
    float temp;
    float wind;
    float rad;
    float airp;
    float hum;
    float evap;

};

class CSVReader
{
public:
    CSVReader();
    ~CSVReader();
    void InputData(std::vector<dataEntry> *startingData);
    bool is_empty(std::ifstream& pFile);
};



