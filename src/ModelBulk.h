#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <memory>


class ModelBulk {

public:

    ModelBulk(const size_t&);
    ~ModelBulk() = default;

    size_t addCommand(const std::string&);

    void clearKeeper();

    bool isStaticMode() { return !nestingLevel; }

    void nextLevel() { ++nestingLevel; }

    void perviousLevel() { --nestingLevel; }

    std::chrono::system_clock::time_point getTime();

    size_t getTimeMilliseconds();

private:
    size_t numberOfCommands;
    //bool dynamicMode = false;
    size_t nestingLevel;
    std::chrono::system_clock::time_point curTime;
    std::vector<std::string> keeperCommands;
};


ModelBulk::ModelBulk(const size_t& inNumber)
        : numberOfCommands(inNumber), nestingLevel(0) {};

size_t ModelBulk::addCommand(const std::string& inCommand) {

    keeperCommands.push_back(inCommand);
    return keeperCommands.size();

}

void ModelBulk::clearKeeper() {
    keeperCommands.clear();
}
