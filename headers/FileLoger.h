#pragma once

#include "IObserver.h"

/**
    \brief Class for outputting the commands stored in the model to a file. Here is used Observer pattern.
*/
class FileLoger : public IObserver {

public:

    void process(const IModelIterator&) override;

};
