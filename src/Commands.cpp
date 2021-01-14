#include "../headers/Commands.h"


void BeginBlock::doCommand() {

    //curModel->doOut();
    if(curModel->isStaticMode() && !curModel->isEmpty()) {
        curModel->doNotify();
        curModel->clearKeeper();
    }
    curModel->nextLevel();

}

void EndBlock::doCommand() {

    curModel->checkLevel();
    curModel->previousLevel();
    curModel->doOut();

}

void Eof::doCommand() {
    curModel->doOut();
}

void StoreData::doCommand(SPString inData) {

    if(curModel->isEmpty())
        curModel->setTime();

    curModel->addCommand(inData);

    if(curModel->isFull())
        curModel->doOut();

}
