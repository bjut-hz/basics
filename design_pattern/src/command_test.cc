#include "util/testharness.h"
#include "util/basic.h"
#include "command.h"


namespace DP {
	
class CommandTest{};

TEST(CommandTest, All) {
	// 客户端仍需要了解Receiver呢!!!可以直接在command里初始化Receiver
	std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>();
	std::shared_ptr<Command> command = std::make_shared<ConcreteCommand>(receiver);
	std::shared_ptr<Invoker> invoker = std::make_shared<Invoker>();

	invoker->SetCommand(command);
	invoker->ExcuteCommand();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}