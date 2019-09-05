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
};

TEST(SortTest, AllSort) {
	std::vector<int> nums = {};
	std::vector<int> insertion_nums = nums;
	std::vector<int> merge_nums = nums;
	std::vector<int> bubble_nums = nums;


	std::sort(nums.begin(), nums.end());
	sort::InsertionSort(insertion_nums);
	sort::MergeSort(merge_nums);
	sort::BubbleSort(bubble_nums);
	AssertVectorEq(nums, insertion_nums);
	AssertVectorEq(nums, merge_nums);
	AssertVectorEq(nums, bubble_nums);

	nums = {1};
	insertion_nums = nums;
	merge_nums = nums;
	bubble_nums = nums;

	std::sort(nums.begin(), nums.end());
	sort::InsertionSort(insertion_nums);
	sort::MergeSort(merge_nums);
	sort::BubbleSort(bubble_nums);
	AssertVectorEq(nums, insertion_nums);
	AssertVectorEq(nums, merge_nums);
	AssertVectorEq(nums, bubble_nums);

	nums = {3, 2, 1, 12, 2, 3, 2};
	insertion_nums = nums;
	merge_nums = nums;
	bubble_nums = nums;

	std::sort(nums.begin(), nums.end());
	sort::InsertionSort(insertion_nums);
	sort::MergeSort(merge_nums);
	sort::BubbleSort(bubble_nums);
	AssertVectorEq(nums, insertion_nums);
	AssertVectorEq(nums, merge_nums);
	AssertVectorEq(nums, bubble_nums);
};


} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}