#define BOOST_TEST_MODULE bulk_test

#include "ModelBulk.h"
#include "Handler.h"
#include "ConsolePrinter.h"
#include <boost/test/unit_test.hpp>
#include <ostream>
#include <sstream>
#include <vector>

class MakeHandler {

public:

    MakeHandler() = default;

    std::unique_ptr<Handler>
      makeUniquePtr(const size_t& numCommands, std::istream& inStream) {

        auto bulk = std::make_shared<ModelBulk>(numCommands);

        std::unique_ptr<IObserver> printer = std::make_unique<ConsolePrinter>();

        bulk->subscribe(std::move(printer));

        auto factory   = std::make_unique<FactoryCommands>();

        factory->addCommand(CMD::BEG, std::make_unique<BeginBlock>(bulk));
        factory->addCommand(CMD::END, std::make_unique<EndBlock>(bulk));
        factory->addCommand(CMD::EF, std::make_unique<Eof>(bulk));
        factory->addCommand(CMD::ADD, std::make_unique<StoreData>(bulk));

        return std::make_unique<Handler>(std::move(factory), inStream);

    }
};


bool bulkTest(size_t sizeBulk, const std::string& commands, const std::string& expectedOut) {

    std::ostringstream realOutStream;
    auto cout_buff = std::cout.rdbuf();
    std::cout.rdbuf(realOutStream.rdbuf());

    std::istringstream inSStream(commands);

    auto commandsHandler = MakeHandler().makeUniquePtr(sizeBulk, inSStream);
    commandsHandler->loop();

    std::cout.rdbuf(cout_buff);

    return expectedOut == realOutStream.str();

}


BOOST_AUTO_TEST_SUITE(bulk_test)

    BOOST_AUTO_TEST_CASE(TreeSizeBulk) {

        std::string commands = "cmd1 cmd2 cmd3\n";
        std::string expected = "bulk: cmd1, cmd2, cmd3\n";

        BOOST_REQUIRE(bulkTest(3, commands, expected));

    }

    BOOST_AUTO_TEST_CASE(OneSizeBulk) {

        std::string commands = "cmd1 cmd2 cmd3\n";
        std::string expected = "bulk: cmd1\nbulk: cmd2\nbulk: cmd3\n";

        BOOST_REQUIRE(bulkTest(1, commands, expected));

    }

    BOOST_AUTO_TEST_CASE(BulkDifferentBlocks) {

        std::vector<std::pair<std::string, std::string>> testData {
            std::make_pair("cmd1 cmd2 { cmd3 cmd4 cmd5 }\n", "bulk: cmd1, cmd2\nbulk: cmd3, cmd4, cmd5\n"),
            std::make_pair("cmd1 { cmd2 } cmd3\n", "bulk: cmd1\nbulk: cmd2\nbulk: cmd3\n"),
            std::make_pair("{ cmd1 } { cmd2 { cmd3 cmd4 } } cmd5 cmd6\n", "bulk: cmd1\nbulk: cmd2, cmd3, cmd4\nbulk: cmd5, cmd6\n"),
            std::make_pair("{ cmd1 } { cmd2 cmd3 cmd4 cmd5 }\n", "bulk: cmd1\nbulk: cmd2, cmd3, cmd4, cmd5\n"),
            std::make_pair("{ }\n{ cmd1 {\n{ { cmd2 } }\n} }\n", "bulk: cmd1, cmd2\n"),
        };

        for (const auto pair : testData) {
            BOOST_REQUIRE(bulkTest(3, pair.first, pair.second));
        }

    }

    BOOST_AUTO_TEST_CASE(BracesError) {

        std::string commands = "cmd1 { cmd3 } }\n";
        std::string expected = "bulk: cmd1\nbulk: cmd3\n";

        BOOST_REQUIRE_THROW(bulkTest(1, commands, expected), std::logic_error);

    }

}
