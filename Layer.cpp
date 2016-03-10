#include "Layer.h"

Layer::Layer()
{
    initNodes();
}

Layer::~Layer()
{
}

//work out this layer's s values, then u values using sigmoid function
void Layer::FeedForward() {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        int s = 0 + nodes[i].bias;
        for (unsigned int j = 0; j < nodes[i].weights.size(); j++) {
            s += inputs[j] * nodes[i].weights[j];
        }
        nodes[i].output = 1/1+(std::exp(-s));
    }
}

//outputs of every node on this layer
std::vector<float> Layer::allOutputs() {
    std::vector<float> allLayerOutputs;
    for (unsigned int i = 0; i < nodes.size(); i++) {
        allLayerOutputs.push_back(nodes[i].output);
    }
    return(allLayerOutputs);
}

//create layers nodes and put in nodes of this layer
void Layer::initNodes() {
    for (int i = 0; i < numberOfNodes; i++) {
        Node newNode;
        newNode.setInitialWeights(numberOfNodes);
        nodes[i] = newNode;
    }
}
