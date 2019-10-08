#include "util/testharness.h"
#include "util/basic.h"

#include "proxy.h"

namespace DP {
	
class ProxyTest{};

TEST(ProxyTest, Proxy) {
	Proxy proxy;
	proxy.Request();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}