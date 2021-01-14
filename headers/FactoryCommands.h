#pragma once

#include <map>
#include "Commands.h"

/**
    \brief Factory class for storing and running commands.
*/
class FactoryCommands {

    using MapComands = std::map<CMD, std::unique_ptr<ICommands>>;

    using SPString = std::shared_ptr<std::string>;

public:
    FactoryCommands() = default;

    void addCommand(CMD, std::unique_ptr<ICommands>);

    //void removeCommand(CMD);

    void run(CMD);

    void run(CMD, SPString);

private:

    MapComands mapCmd;

};

