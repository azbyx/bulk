#include "ModelBulk.h"
#include "Handler.h"
//#include "ConsolePrinter.h"
//#include "FileLoger.h"

#include <iostream>
#include <cstdlib>


int main(int, char**) {
//(int argc, char** argv) {

    std::unique_ptr<ModelBulk> bulk = std::make_unique<ModelBulk>(3ULL);
    std::unique_ptr<Handler> handler = std::make_unique<Handler>(std::move(bulk), std::cin);

    handler->loop();

    /*
    if(argc != 2) {
        std::cout << "Usage: bulk N \nWhere N is size of block.";
        return 1;
    }
    else {

        int commandsNumber = atoll(argv[1]);

        if(commandsNumber > 0) {

            auto commandHandler = std::make_unique<IHandler>(commandsNumber, std::cin);
            auto fileLoger      = FileLoger();
            auto consolePrinter = ConsolePrinter();

            commandHandler->subscribe(&consolePrinter);
            commandHandler->subscribe(&fileLoger);

            commandHandler->process();
        }
        else {
            std::cout << argv[1] << " isn't a positive number." << std::endl;
        }
    }
    */
    return 0;
}
