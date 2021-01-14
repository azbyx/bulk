#include "../headers/ModelBulk.h"

ModelBulk::ModelBulk(const size_t& inNumber)
    : numberOfCommands(inNumber), nestingLevel(0) {}

void ModelBulk::addCommand(SPstring inCommand) { keeperCommands.push_back(inCommand); }

void ModelBulk::clearKeeper(){ keeperCommands.clear(); }

bool ModelBulk::isStaticMode() const { return !nestingLevel; }

bool ModelBulk::isFull() { return numberOfCommands == keeperCommands.size(); }

void ModelBulk::nextLevel() { ++nestingLevel; }

void ModelBulk::previousLevel() { --nestingLevel; }

bool ModelBulk::isEmpty() const { return keeperCommands.empty(); }

void ModelBulk::checkLevel() {

    if(isStaticMode())
        throw std::out_of_range("Dynamic block parsing isn't correct.");

}

void ModelBulk::setTime() {

        using namespace std::chrono;

        auto timePoint = time_point_cast<milliseconds>(system_clock::now());
        auto timeMilliSeconds = timePoint.time_since_epoch().count();

        fistCommandTime = std::to_string(timeMilliSeconds);

}

void ModelBulk::doOut() {

    if(isStaticMode() && !isEmpty()) {
        notify(*this);
        clearKeeper();
    }
}

void ModelBulk::doNotify() { notify(*this); }

std::string ModelBulk::getTime() const { return fistCommandTime;}

iterator ModelBulk::cbegin() const { return iterator(keeperCommands.cbegin());}

iterator ModelBulk::cend() const { return iterator(keeperCommands.cend());}
