#pragma once

#include "IModelIterator.h"

/**
    \brief Interface provided to the browser of the object being observed
*/
class IObserver {
public:
    virtual ~IObserver() = default;

    virtual void process(const IModelIterator&) = 0;
};
