#include "util/testharness.h"
#include "util/basic.h"
#include "iterator.h"

namespace DP {
	
class IteratorTest{};

TEST(IteratorTest, All) {
	MyList<int> list;
	std::vector<int> nums = { 1, 2, 3, 4 };

	list.Add(nums[0]);
	list.Add(nums[1]);
	list.Add(nums[2]);
	list.Add(nums[3]);

	auto iter = list.CreateIterator();
	iter->First();
	std::size_t i = 0;
	while (!iter->IsDone()) {
		ASSERT_EQ(iter->CurrentItem(), nums[i++]);
		iter->Next();
	}

	iter->First();
	iter->CurrentItem() = 100;
	ASSERT_EQ(iter->CurrentItem(), 100);
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}