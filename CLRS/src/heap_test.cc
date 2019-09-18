#include "util/testharness.h"
#include "util/basic.h"
#include "heap.h"


namespace CLRS {
	
class HeapTest{};

TEST(HeapTest, ALL) {
	std::vector<int> nums = {1, 2, 3, 4, 5};
	MaxHeap max_heap(nums);

	ASSERT_EQ(5, max_heap.max());
	max_heap.ExtractMax();

	ASSERT_EQ(4, max_heap.max());


	max_heap.Insert(100);
	max_heap.Insert(1000);

	ASSERT_EQ(1000, max_heap.max());
	max_heap.ExtractMax();
	ASSERT_EQ(100, max_heap.max());

	ASSERT_EQ(5, max_heap.size());


	MaxHeap max_heap2;
	max_heap2.Insert(2);
	max_heap2.Insert(3);
	max_heap2.Insert(3);
	max_heap2.Insert(3);
	max_heap2.Insert(4);
	max_heap2.Insert(5);
	ASSERT_EQ(6, max_heap2.size());

	ASSERT_EQ(5, max_heap2.ExtractMax());
	ASSERT_EQ(4, max_heap2.ExtractMax());
	ASSERT_EQ(3, max_heap2.ExtractMax());
	ASSERT_EQ(3, max_heap2.ExtractMax());
	ASSERT_EQ(2, max_heap2.size());

};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}