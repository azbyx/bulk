#pragma once

#include "IObserver.h"
#include <iostream>
#include <experimental/iterator>

class ConsolePrinter : public IObserver {
public:
    void process(const ContanerType& commands, const size_t) override {
        if(!commands.empty()) {
            std::cout << "bulk: ";
            std::copy(std::begin(commands), std::end(commands), std::experimental::make_ostream_joiner(std::cout, ", "));
            std::cout << std::endl;
        }
    }
};
