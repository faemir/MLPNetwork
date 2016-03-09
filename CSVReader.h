#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

struct dataEntry {
    std::string date;
    float temp;
    float wind;
    float rad;
    float airp;
    int hum;
    float evap;

};

class CSVReader
{
public:
    CSVReader();
    ~CSVReader();
    void InputData();
    bool is_empty(std::ifstream& pFile);
};



