#include<algorithm>

#include "util/testharness.h"
#include "util/basic.h"
#include "sort.h"

namespace CLRS {
	
class SortTest{
	public:
	void AssertVectorEq(std::vector<int>& a, std::vector<int>& b) {
		ASSERT_EQ(a.size(), b.size());
		for(size_t i = 0; i < a.size(); ++i) {
			ASSERT_EQ(a[i], b[i]);
		}
	}

	void TestSort(std::vector<int>& nums) {
		std::vector<int> insertion_nums = nums;
		std::vector<int> merge_nums = nums;
		std::vector<int> bubble_nums = nums;
		std::vector<int> heap_nums = nums;
		std::vector<int> quick_nums = nums;

		std::sort(nums.begin(), nums.end());
		sort::InsertionSort(insertion_nums);
		sort::MergeSort(merge_nums);
		sort::BubbleSort(bubble_nums);
		sort::HeapSort(heap_nums);
		sort::QuickSort(quick_nums);
		AssertVectorEq(nums, insertion_nums);
		AssertVectorEq(nums, merge_nums);
		AssertVectorEq(nums, bubble_nums);
		AssertVectorEq(nums, heap_nums);
		AssertVectorEq(nums, quick_nums);
	}
};

TEST(SortTest, AllSort) {
	std::vector<int> nums = {};
	TestSort(nums);

	nums = {1};
	TestSort(nums);

	nums = {3, 2, 1, 12, 2, 3, 2};
	TestSort(nums);

	nums = { 3, 2, 1, 1, 2, 3, 34, 5, 0, -1, 1, 12, 2, 3, 2 };
	TestSort(nums);
};


} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}