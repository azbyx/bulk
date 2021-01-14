#pragma once

#include <list>
#include "IModelIterator.h"
#include "IObserver.h"


/**
    \brief Class interface for notifying about the need to process the command model.
*/

class Observable {

    using SPIObserver = std::shared_ptr<IObserver>;

protected:

    std::list<SPIObserver> subscribers;

public:
    virtual ~Observable() = default;

    void notify(const IModelIterator&);

    void subscribe(SPIObserver);
};
