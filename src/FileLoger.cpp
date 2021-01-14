#include <iostream>
#include <fstream>
#include <experimental/iterator>
#include "../headers/FileLoger.h"

void FileLoger::process(const IModelIterator& commands) {

    std::ofstream file("bulk" + commands.getTime() + ".log");
    std::copy(commands.cbegin(), commands.cend(), std::experimental::make_ostream_joiner(file, ", "));
    file << std::endl;

}
