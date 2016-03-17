#include "Node.h"

Node::Node()
{
    setInitialBias();
}

Node::~Node()
{
}

void Node::setInitialBias() {
    bias = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Node::setInitialWeights(int prevNumNodes) {
    weights.resize(prevNumNodes);
    for (int i = 0; i < prevNumNodes; i++) {
        weights[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
}