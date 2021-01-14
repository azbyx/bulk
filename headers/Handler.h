#pragma once

#include <iostream>
#include <iterator>
#include "FactoryCommands.h"

/**
    \brief Class for reading commands from stream and calling handler commands.
*/

class Handler {

    using SPFactoryComands = std::shared_ptr<FactoryCommands>;

    using UPString = std::unique_ptr<std::string>;

public:

    Handler(SPFactoryComands, std::istream&);

    ~Handler() = default;

    /**
    \brief Starts a commands reading loop.
    */
    void loop();

    /**
    \brief Reads next command from stream.
    */
    void readCommand();

    /**
    \brief Returns whether EOF was in the last command.
    */
    bool isEof();

private:

    bool eof = false;

    SPFactoryComands cmd;

    UPString data;

    std::istream& input;
};

