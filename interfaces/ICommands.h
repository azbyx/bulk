#pragma once

#include <memory>
#include <string>

/**
    \brief Interface for using commands.
*/
class ICommands {

public:
    virtual ~ICommands() = default;

    virtual void doCommand(std::shared_ptr<std::string>) = 0;

    virtual void doCommand() = 0;
};

