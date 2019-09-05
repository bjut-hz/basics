#include "util/testharness.h"
#include "util/basic.h"
#include "maximum_subarray.h"

#include<vector>
#include<iostream>

namespace CLRS {
	
class MaximumSubarrayTest{};

TEST(MaximumSubarrayTest, All) {
	std::vector<int> nums = {1, 2, -9, 3, 1, -2, 3, 5, -7, 3};
	auto result = MaximumSubarraySolution::Solution1(nums);
	std::cout << result << std::endl;
	ASSERT_EQ(MaximumSubarraySolution::Solution1(nums), result);
	ASSERT_EQ(MaximumSubarraySolution::Solution2(nums), result);
	ASSERT_EQ(MaximumSubarraySolution::Solution3(nums), result);

};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}