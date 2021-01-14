#pragma once

#include <chrono>
#include "Observable.h"
#include "IModelCommand.h"

/**
    \brief Class for storing commands and state for processing.
    Inherits from interfaces for handling its state, outputting it, and iterating over it.
*/

class ModelBulk : public Observable, public IModelIterator, public IModelCommand {

public:

    ModelBulk(const size_t&);

    ~ModelBulk() = default;


    friend iterator;

    iterator cbegin() const override;

    iterator cend() const override;

    std::string getTime() const override;


    void doOut() override;

    void addCommand(SPstring inCommand) override;

    bool isStaticMode() const override;

    bool isFull() override;

    void nextLevel() override;

    void previousLevel() override;

    void setTime() override;

    void checkLevel() override;

    bool isEmpty() const override;

    void doNotify() override;

    void clearKeeper() override;

private:

    size_t numberOfCommands; ///The maximum number of commands to be output in static mode.

    size_t nestingLevel;     ///Dynamic mode nesting level. If nestingLevel = 0, then the model is in static mode.

    std::string fistCommandTime; ///First command time. The output file will be named by it.

    std::vector<SPstring> keeperCommands; ///Storage container

};

