#pragma once

#include <vector>
#include <tgmath.h>
#include "Node.h"
#include <iostream>

class Layer
{
public:
    Layer();
    ~Layer();

    //inputs from previous layer
    std::vector<float> inputs;
    //nodes of this layer
    std::vector<Node> nodes;
    //number of nodes on this layer
    int numberOfNodes;

    //calculate outputs in forwards propogation
    void ForwardPass();
    //output of all nodes in the layer
    std::vector<float> allOutputs();
    //creates nodes for the layer
    void initNodes(int prevNumNodes);
};
