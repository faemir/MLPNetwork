#include "Layer.h"

Layer::Layer()
{
    inputs.resize(5);
}

Layer::~Layer()
{
}

//work out each node s value, then u value using sigmoid function
void Layer::ForwardPass() {
    for (unsigned int i = 0; i < nodes.size(); i++) {
        float s = 0;
        s += nodes[i].bias;
        for (unsigned int j = 0; j < nodes[i].weights.size(); j++) {
            s += inputs[j] * nodes[i].weights[j];
            std::cout << "s output: " << s << "\n";
        }
        nodes[i].output = 1 / ( 1 + std::exp(-s));
        std::cout << "u output: " << nodes[i].output << "\n";
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
void Layer::initNodes(int prevNumNodes) {
    for (int i = 0; i < numberOfNodes; i++) {
        Node newNode;
        nodes[i] = newNode;
        nodes[i].setInitialWeights(prevNumNodes);
    }
}
