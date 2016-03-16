#include "Layer.h"

Layer::Layer()
{
    inputs.resize(5);
    initNodes();
}

Layer::~Layer()
{
}

//work out this layer's s values, then u values using sigmoid function
void Layer::ForwardPass() {
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

//create nodes for this layer and adds to vector
void Layer::initNodes() {
    for (int i = 0; i < numberOfNodes; i++) {
        Node newNode;
        newNode.setInitialWeights(numberOfNodes);
        nodes[i] = newNode;
    }
}
