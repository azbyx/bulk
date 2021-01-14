#pragma once

#include "ModelBulk.h"
#include "Handler.h"
#include "ConsolePrinter.h"
#include "FileLoger.h"

/**
    \brief Helper class for customizing the application.
*/
class MakeHandler {

public:

    MakeHandler() = default;

    std::unique_ptr<Handler>
      operator() (const size_t& numCommands) {

        auto bulk    = std::make_shared<ModelBulk>(numCommands);

        std::unique_ptr<IObserver> printer = std::make_unique<ConsolePrinter>();
        std::unique_ptr<IObserver> loger   = std::make_unique<FileLoger>();

        bulk->subscribe(std::move(printer));
        bulk->subscribe(std::move(loger));

        auto factory   = std::make_unique<FactoryCommands>();

        factory->addCommand(CMD::BEG, std::make_unique<BeginBlock>(bulk));
        factory->addCommand(CMD::END, std::make_unique<EndBlock>(bulk));
        factory->addCommand(CMD::EF, std::make_unique<Eof>(bulk));
        factory->addCommand(CMD::ADD, std::make_unique<StoreData>(bulk));

        return std::make_unique<Handler>(std::move(factory), std::cin);

    }
};
