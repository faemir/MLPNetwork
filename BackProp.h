#pragma once

#include "Layer.h"
#include <vector>

class BackProp
{
public:
    BackProp();
    ~BackProp();

    std::vector<Layer> layers;
    int numberOfSamples;
    int currentSample;

    void ForwardPass();
    void BackPass();
    void ErrorCalc();
    void PassError();
};
