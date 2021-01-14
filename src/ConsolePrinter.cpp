#include <iostream>
#include <experimental/iterator>
#include "ConsolePrinter.h"

void ConsolePrinter::process(const IModelIterator& commands) {

    std::cout << "bulk: ";
    std::copy(commands.cbegin(), commands.cend(), std::experimental::make_ostream_joiner(std::cout, ", "));
    std::cout << std::endl;

}
