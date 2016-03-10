#pragma once

#include <random>
#include <vector>

class Node
{
public:
    Node();
    ~Node();

    //weighs of connected previous layer
    std::vector<float> weights;

    //bias on this node
    float bias;

    //output from this node
    float output;

    //signal error output
    float signalError;

    //random initial bias
    void setInitialBias();

    //random initial weights from this node to next layer
    void setInitialWeights(int numPrevNodes);
};

