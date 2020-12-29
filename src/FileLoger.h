#pragma once

#include "IObserver.h"
#include <iostream>
#include <fstream>
#include <experimental/iterator>


class FileLoger : public IObserver {
public:
    void process(const ContanerType& commands, const size_t time) override {
        if(!commands.empty()) {
            std::ofstream file("bulk" + std::to_string(time) + ".log");
            std::copy(std::begin(commands), std::end(commands), std::experimental::make_ostream_joiner(file, ", "));
            file << std::endl;
        }
    }
};
