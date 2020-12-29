#pragma once

#include <map>
#include <string>
#include <memory>
#include <iostream>
//#include "Command.h"


class Handler {
public:
    Handler() = default;
    ~Handler() = default;

    void readCommand();
    bool isEof() { return eof; }

private:

    void doBeginBlock();
    void doEndBlock();
    void doStoreData();
    void doEof();

private:
    bool eof = true;
    std::string data;
};


void Handler::readCommand() {

    std::cin >> data;
    eof = !std::cin.eof();
    if(!eof)
        doEof();
    else if(data == "{")
        doBeginBlock();
    else if(data == "}")
        doEndBlock();
    else
        doStoreData();
}


void Handler::doBeginBlock() {
    std::cout << "CommandBeginBlock " << std::endl;
}


void Handler::doEndBlock() {
    std::cout << "CommandEndBlock " << std::endl;
}


void Handler::doStoreData() {
    std::cout << data << " CommandStoreData " << std::endl;
}

void Handler::doEof() {
    std::cout << " CommandEOF " << std::endl;
}
