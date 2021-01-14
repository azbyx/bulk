#pragma once

#include "ModelIterator.h"

/**
    \brief Interface for outputting keeped commands and income time of the first command.
*/

class IModelIterator {
public:
    virtual ~IModelIterator() = default;

    virtual iterator cbegin() const = 0;

    virtual iterator cend() const = 0;

    virtual std::string getTime() const = 0;
};
