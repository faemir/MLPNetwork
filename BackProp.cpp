#include "BackProp.h"


BackProp::BackProp(std::vector<dataEntry> *startingData)
{
    numberOfSamples = startingData->size();
    iterations = 50;
    //lots of object initialisation
    layers.resize(3); //we need 3 layers including the input and output layers
    layers[0].numberOfNodes = 5;
    layers[1].numberOfNodes = 5;
    layers[2].numberOfNodes = 1;
    layers[0].nodes.resize(layers[0].numberOfNodes);
    layers[1].nodes.resize(layers[1].numberOfNodes);
    layers[2].nodes.resize(layers[2].numberOfNodes);
    expectedResults.resize(numberOfSamples);
    for (int i = 0; i < numberOfSamples; i++) {
        expectedResults[i] = (*startingData)[i].evap;
    }
    for (unsigned int j = 0; j < layers[1].nodes.size(); j++) {
        layers[1].nodes[j].weights.resize(5);
        layers[1].initNodes(5);
    }
    for (unsigned int k = 0; k < layers[2].nodes.size(); k++) {
        layers[2].nodes[k].weights.resize(5);
        layers[2].initNodes(5);
    }

    Training(startingData);
}

BackProp::~BackProp()
{
}


void BackProp::CallForwardPasses() {
    //pass input to hidden layer
    for (unsigned int i = 0; i < layers[0].nodes.size(); i++) {
        layers[0].nodes[i].output = layers[0].inputs[i];
    }
    layers[1].inputs = layers[0].inputs;
    std::cout << "hidden forward pass \n";
    layers[1].ForwardPass();
    layers[2].inputs = layers[1].allOutputs();
    std::cout << "output forward pass \n";
    layers[2].ForwardPass();
}

//working out the δ for hidden layer and output
//using the formulas from slides
void BackProp::ErrorCalc() {
    //calculate the final error
    //δ = ((c - u) * ( u * (1 - u))
    for (unsigned int i = 0; i < layers[2].nodes.size(); i++) {
        float uOuter = layers[2].nodes[i].output;
        float c = expectedResults[currentSample];
        layers[2].nodes[i].signalError = (c - uOuter) * (uOuter * (1 - uOuter));
    }
    //calculate errors in the hidden layer
    //δ = ((weight * δfinal) * ( u * (1 - u))
    for (unsigned int j = 0; j < layers[1].nodes.size(); j++) {
        float fromOuterLayer = layers[2].nodes[0].weights[j] * layers[2].nodes[0].signalError;
        float uHidden = layers[1].nodes[j].output;
        layers[1].nodes[j].signalError = fromOuterLayer * (uHidden * (1 - uHidden));
    }
}

//work out new weighting for each connection
//from input layer to hidden and hidden to output
//new weight = weight + p * δ * u
void BackProp::PassErrorWeights() {
    int p = 0.1; //step parameter
    for (unsigned int i = 2; i > 0; i--) {
        for (unsigned int j = 0; j < layers[i].nodes.size(); j++) {
            for (unsigned int k = 0; k < layers[i-1].nodes.size(); k++) {
                float newW = p * layers[i-1].nodes[k].signalError * layers[i].nodes[j].output;
                layers[i].nodes[j].weights[k] += newW;
            }
        }
    }
}

//train the MLP on the first part of data
void BackProp::Training(std::vector<dataEntry> *startingData) {
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < numberOfSamples; i++) {
            currentSample = i;
            //set the input values
            layers[0].inputs[0] = (*startingData)[i].temp;
            layers[0].inputs[1] = (*startingData)[i].wind;
            layers[0].inputs[2] = (*startingData)[i].rad;
            layers[0].inputs[3] = (*startingData)[i].airp;
            layers[0].inputs[4] = (*startingData)[i].hum;
            std::cout << "sample " << currentSample << ": temp: " << layers[0].inputs[0];
            std::cout << " wind: " << layers[0].inputs[1] << " rad: " << layers[0].inputs[2];
            std::cout << " airp: " << layers[0].inputs[3] << " hum: " << layers[0].inputs[4] << " \n";
            //forward pass
            CallForwardPasses();
            //grab result
            actualResults.push_back(layers[2].nodes[0].output);

            //backwards pass
            ErrorCalc();
            PassErrorWeights();
        }
    }
    Results();
}

void BackProp::Results() {
    for (unsigned i = 0; i < actualResults.size(); i++) {
        std::cout << "actual result " << i << ": " << actualResults[i] << "\n";
    }
}