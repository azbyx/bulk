#include "ICommand.h"

Class CommandBeginBlock : ICommand {}

Class CommandEndBlock : ICommand {}

Class CommandDataRead : ICommand {
public:
    CommandDataRead(const std::string& curCommand) : value(curCommand);

    std::string getValue() const { return dataCommand; }

private:
    std::string dataCommand;
}
