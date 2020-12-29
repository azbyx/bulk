#pragma once

#include <string>
#include <vector>
#include <list>
#include <memory>

using ContanerType = std::vector<std::shared_ptr<std::string>>;

class IObserver {
public:
    virtual void process(const ContanerType& cmd, const size_t time) = 0;
};


class IObservable {
public:
    virtual void subscribe(IObserver* observer) = 0;
};


class BaseObservable : public IObservable {
protected:
    std::list<IObserver*> m_subscribers;

    void notify(const ContanerType& cmd, const size_t time);

public:
    void subscribe(IObserver* observer) override;

    const std::list<IObserver*>& subscribers() const;
};
