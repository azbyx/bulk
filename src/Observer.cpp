#include "IObserver.h"

void BaseObservable::notify(const ContanerType& cmd, const size_t time) {
    for(auto subscriber : m_subscribers)
        subscriber->process(cmd, time);
}

void BaseObservable::subscribe(IObserver *observer) {
    m_subscribers.push_back(observer);
}

const std::list<IObserver*>& BaseObservable::subscribers() const {
    return m_subscribers;
}
