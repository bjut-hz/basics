#include "util/testharness.h"
#include "util/basic.h"
#include "composite.h"

namespace DP {
	
class CompositeTest{};

TEST(CompositeTest, All) {
	std::shared_ptr<Composite> root = std::make_shared<Composite>("root");

	auto leaf_a = std::make_shared<Leaf>("Leaf A");
	auto leaf_b = std::make_shared<Leaf>("Leaf B");

	root->Add(std::dynamic_pointer_cast<Component>(leaf_a));
	root->Add(std::dynamic_pointer_cast<Component>(leaf_b));

	std::shared_ptr<Composite> comp = std::make_shared<Composite>("Composite X");
	comp->Add(std::dynamic_pointer_cast<Component>(leaf_a));
	comp->Add(std::dynamic_pointer_cast<Component>(leaf_b));

	root->Add(std::dynamic_pointer_cast<Component>(comp));

	auto leaf_c = std::make_shared<Leaf>("Leaf C");
	root->Add(std::dynamic_pointer_cast<Component>(leaf_c));
	root->Remove(std::dynamic_pointer_cast<Component>(leaf_c));

	comp->Add(std::dynamic_pointer_cast<Component>(leaf_c));

	root->Display(1);
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}