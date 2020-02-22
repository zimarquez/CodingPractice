#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include "helloConfig.h"

void displayCMakeVersion (int argc, char* argv[])
{
    if (argc < 2) {
	    std::cout << argv[0] << " Version " << cmakeLearning_VERSION_MAJOR << "."
		    << cmakeLearning_VERSION_MINOR << std::endl;
	    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    }
}

int main (int argc, char* argv[])
{
    
    printf("hello\n");
    displayCMakeVersion(argc, argv);
    return 0;
}
