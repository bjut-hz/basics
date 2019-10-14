#include "util/testharness.h"
#include "util/basic.h"
#include "chain_of_responsibility.h"
#include <vector>

namespace DP {
	
class ChainOfResponsibilityTest{};

TEST(ChainOfResponsibilityTest, All) {
	std::shared_ptr<Handler> h1 = std::make_shared<ConcreteHandler1>();
	std::shared_ptr<Handler> h2 = std::make_shared<ConcreteHandler2>();
	h1->SetSuccessor(h2);

	std::vector<Request> requests = { {1}, {2}, {10}, {12}, {20}, {100} };
	for(auto& request : requests) {
		h1->HandleRequest(request);
	}
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}