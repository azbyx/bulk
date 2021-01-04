#pragma once

#include <map>
#include <string>
#include <memory>
#include <iostream>
//#include "Command.h"

enum class Comm {BEG, END, STORE, ENDOF};

class Handler {
public:
    Handler(std::shared_ptr<ModelBulk>, std::istream&);
    ~Handler() = default;

    void loop();
    void readCommand();
    bool isEof() { return eof; }

private:

    void doBeginBlock();
    void doEndBlock();
    void doStoreData();
    void doEof();

private:
    bool eof = false;
    std::shared_ptr<ModelBulk> curModel;
    std::istream& input;
};



Handler::Handler(std::shared_ptr<ModelBulk> inModel, std::istream& inParam)
    : curModel(inModel), input(inParam) {}

void Handler::readCommand() {

    std::string data;
    input >> data;
    eof = input.eof();
    if(eof)
        doEof();
    else if(data == "{")
        doBeginBlock();
    else if(data == "}")
        doEndBlock();
    else
        doStoreData();
}

void Handler::loop() {

    while(!isEof())
        readCommand();
}


void Handler::doBeginBlock() {
    std::cout << "CommandBeginBlock " << std::endl;
}


void Handler::doEndBlock() {
    std::cout << "CommandEndBlock " << std::endl;
}


void Handler::doStoreData() {
    std::cout << " CommandStoreData " << std::endl;
    curModel.push_back();
}

void Handler::doEof() {
    std::cout << " CommandEOF " << std::endl;
}
