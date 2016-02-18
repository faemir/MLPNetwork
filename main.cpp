#include <stdio.h>
#include <iostream>
#include "dataInput.h"


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

void inputData() {
	std::string newline;
	dataEntry theInputData;
	while (newline[0] != '\0') {
		std::cin >> newline;
		std::string tempStr;
		for (unsigned int i = 0; i < newline.length() - 1; i++) {
			if (newline[i] != ',') {
				tempStr += newline[i];
			}
		}
	}
}