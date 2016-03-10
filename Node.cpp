#include "Node.h"

Node::Node()
{
    setInitialBias();
}

Node::~Node()
{
}

void Node::setInitialBias() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
    bias = dist(mt);
}

void Node::setInitialWeights(int numPrevNodes) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
    for (int i = 0; i < numPrevNodes; i++) {
        weights[i] = dist(mt);
    }
}