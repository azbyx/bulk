#include "../headers/Handler.h"


Handler::Handler(SPFactoryComands inFactoryCmd, std::istream& inStream)
    : cmd(inFactoryCmd), input(inStream) {}


void Handler::readCommand() {

    data = std::make_unique<std::string>(*std::istream_iterator<std::string>(input));
    eof = input.eof();
    if(eof)
        cmd->run(CMD::EF);
    else if("{" == *data)
        cmd->run(CMD::BEG);
    else if("}" == *data)
        cmd->run(CMD::END);
    else
        cmd->run(CMD::ADD, std::move(data));
}

bool Handler::isEof() { return eof; }

void Handler::loop() {

    while(!isEof())
        readCommand();

}
