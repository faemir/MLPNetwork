#pragma once
#include <string>

class dataInput
{
public:
    dataInput();
    ~dataInput();

};

struct dataEntry {
	std::string date;
	float temp;
	float wind;
	float rad;
	float airp;
	int hum;
	float evap;

};
