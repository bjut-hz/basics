#include "util/testharness.h"
#include "util/basic.h"
#include "builder.h"

namespace DP {
	
class BuilderTest{};

TEST(BuilderTest, All) {
	ConcreteBuilder1 builder1;
	ConcreteBuilder2 builder2;

	Director director;
	auto& product1 = director.Construct(builder1);
	auto& product2 = director.Construct(builder2);
	
	product1.Show();
	product2.Show();
};

} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}