#include <iostream>
#include "CSVReader.h"

int main(int argc, char **argv)
{
    std::cout << "Advanced AI Systems Coursework. \n\n";
    CSVReader dataInputter;
    std::vector<dataEntry> startingData;

    dataInputter.InputData(&startingData);
    system("pause");
    return 0;
}