#pragma once

#include "Layer.h"
#include <vector>
#include "CSVReader.h"

class BackProp
{
public:
    BackProp(std::vector<dataEntry> *startingData);
    ~BackProp();

    std::vector<Layer> layers;
    int numberOfSamples;
    int currentSample;
    std::vector<float> expectedResults;
    std::vector<float> actualResults;
    int iterations;

    void CallForwardPasses();
    void ErrorCalc();
    void PassErrorWeights();
    void Training(std::vector<dataEntry> *startingData);
    void Results();
};
