#include "util/testharness.h"
#include "util/basic.h"
#include "flyweight.h"

namespace DP {
	
class FlyweightTest{};

TEST(FlyweightTest, All) {
	int extrinsic_state = 99;
	auto factory = std::make_shared<FlyweightFactory>();
	std::shared_ptr<Flyweight> fx = factory->GetFlyweight("X");
	fx->Operation(--extrinsic_state);

	std::shared_ptr<Flyweight> fy = factory->GetFlyweight("Y");
	fy->Operation(--extrinsic_state);

	std::shared_ptr<Flyweight> fz = factory->GetFlyweight("Z");
	fz->Operation(--extrinsic_state);

	auto uf = std::make_shared<UnsharedConcreteFlyweight>();
	uf->Operation(--extrinsic_state);
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}