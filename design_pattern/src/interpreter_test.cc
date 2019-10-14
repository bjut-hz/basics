#include "util/testharness.h"
#include "util/basic.h"
#include "interpreter.h"
#include <vector>

namespace DP {
	
class InterpreterTest{};

TEST(InterpreterTest, All) {
	Context context{"hello world"};
	std::vector<std::shared_ptr<AbstractExpression>> vecs;
	vecs.push_back(std::make_shared<TerminalExpression>());
	vecs.push_back(std::make_shared<NonterminalExpression>());
	vecs.push_back(std::make_shared<TerminalExpression>());
	vecs.push_back(std::make_shared<TerminalExpression>());

	for(auto& exp : vecs) {
		exp->Interpret(context);
	}
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}