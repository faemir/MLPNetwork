#include <iostream>
#include "CSVReader.h"
#include "BackProp.h"
#include <ctime>

int main(int argc, char **argv)
{
    std::cout << "Advanced AI Systems Coursework. \n\n";
    std::srand( std::time( NULL ));
    CSVReader dataInputter;
    std::vector<dataEntry> startingData;
    dataInputter.InputData(&startingData);
    BackProp theMLP(&startingData);
    system("pause");
    return 0;
}