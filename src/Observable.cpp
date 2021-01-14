#include "../headers/Observable.h"


void Observable::notify(const IModelIterator& model) {
    for(auto subscriber : subscribers)
        subscriber->process(model);
}

void Observable::subscribe(SPIObserver observer) {
    subscribers.push_back(observer);
}
