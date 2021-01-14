#pragma once

#include <string>
#include <memory>

/**
    \brief Interface that allows you to manage the state of the command keeper.
*/
class IModelCommand {

public:

    using SPstring = std::shared_ptr<std::string>;

    virtual ~IModelCommand() = default;

    virtual void doOut() = 0;

    virtual void addCommand(SPstring inCommand) = 0;

    virtual bool isStaticMode() const = 0;

    virtual bool isFull() = 0;

    virtual bool isEmpty() const = 0;

    virtual void nextLevel() = 0;

    virtual void previousLevel() = 0;

    virtual void checkLevel() = 0;

    virtual void setTime() = 0;

    virtual void doNotify() = 0;

    virtual void clearKeeper() = 0;

};
