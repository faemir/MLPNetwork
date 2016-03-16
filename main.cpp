#include <iostream>
#include "CSVReader.h"
#include "BackProp.h"

int main(int argc, char **argv)
{
    std::cout << "Advanced AI Systems Coursework. \n\n";
    CSVReader dataInputter;
    std::vector<dataEntry> startingData;
    dataInputter.InputData(&startingData);
    BackProp theMLP(&startingData);
    system("pause");
    return 0;
}