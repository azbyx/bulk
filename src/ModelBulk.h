#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <memory>


class ModelBulk {

public:

    ModelBulk(const size_t&, std::istream&);
    ~ModelBulk() = default;

    readCommand();

    std::chrono::system_clock::time_point getTime();

    size_t getTimeMilliseconds();

private:

    size_t numberOfCommands;

    std::istream& inputStream;

    std::chrono::system_clock::time_point curTime;

    std::vector<std::shared_ptr<std::string>> keeperCommands;
};
