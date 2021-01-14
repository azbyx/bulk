#pragma once

#include "IObserver.h"

/**
    \brief Class for printing the commands stored in the model to a stream. Here is used Observer pattern.
*/
class ConsolePrinter : public IObserver {

public:

    void process(const IModelIterator&) override;

};
