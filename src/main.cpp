/**
    \file
    \mainpage Homework 6 of the course "C ++ Developer. Professional" LLC "Otus Online Education"
	\brief Homework 6 of the course "C ++ Developer. Professional" LLC "Otus Online Education"
	\author Bulanov Sergey
	\version 0.1.0
	\date January 2020
	\warning There was done for educational purposes.

*The purpose of the work is to use design and architectural patterns for building applications
*/

#include "MakeHandler.h"

/**
    \brief Main function

    \param argc Number of in arguments
    \param argv Pointer to list of char* arguments
*/
int main(int argc, char** argv) {

    if(argc != 2) {
        std::cout << "Usage: bulk N \nWhere N is size of block.";
        return 1;
    }
    else {

        int commandsNumber = atoll(argv[1]);

        if(commandsNumber > 0) {
            auto commandsHandler = MakeHandler()(commandsNumber);
            commandsHandler->loop();
        }
        else {
            std::cout << argv[1] << " isn't a positive number." << std::endl;
        }

    }

    return 0;
}
