#pragma once

#include "ICommands.h"
#include "IModelCommand.h"

enum class CMD {BEG, END, EF, ADD};


/**
    \brief base class for creating commands.
*/
class BaseCommands : public ICommands {

public:
    using SPString = std::shared_ptr<std::string>;
    using SPModel = std::shared_ptr<IModelCommand>;

    BaseCommands(SPModel inModel) : curModel(inModel) {}

    virtual void doCommand(SPString)  override {};

    virtual void doCommand()  override {};

protected:
    SPModel curModel;
};

/**
    \brief Class for running command BeginBlock - "{".
*/
class BeginBlock : public BaseCommands {

public:
    BeginBlock(SPModel inModel) : BaseCommands(inModel) {}

    void doCommand() override;

};

/**
    \brief Class for running command EndBlock - "}".
*/
class EndBlock : public BaseCommands {

public:
    EndBlock(SPModel inModel) : BaseCommands(inModel) {}

    void doCommand() override;

};

/**
    \brief Class for running command EOF.
*/
class Eof : public BaseCommands {

public:
    Eof(SPModel inModel) : BaseCommands(inModel) {}

    void doCommand() override;

};

/**
    \brief Class for running command StoreData.
*/
class StoreData : public BaseCommands {

public:
    StoreData(SPModel inModel) : BaseCommands(inModel) {}

    void doCommand(SPString) override;

};
