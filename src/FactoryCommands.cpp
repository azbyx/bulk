#include "../headers/FactoryCommands.h"

void FactoryCommands::run(CMD inCmd) {
    mapCmd[inCmd]->doCommand();
}

void FactoryCommands::run(CMD inCmd, SPString inData) {
    mapCmd[inCmd]->doCommand(inData);
}


void FactoryCommands::addCommand(CMD inCmd, std::unique_ptr<ICommands> inCommand) {
    mapCmd.emplace(inCmd, std::move(inCommand));
}

