#include "util/testharness.h"
#include "util/basic.h"
#include "order_statistic.h"
#include<algorithm>


namespace CLRS {
	
class OrderStatisticTest{};

TEST(OrderStatisticTest, Maximum) {
	std::vector<int> nums = {12, 3, 4, 5, 6, 3, 2};
	ASSERT_EQ(Maximum(nums), 12);
};

TEST(OrderStatisticTest, Minimum) {
	std::vector<int> nums = {12, 3, 4, 5, 6, 3, 2, -10};
	ASSERT_EQ(Minimum(nums), -10);
};

TEST(OrderStatisticTest, MaxAndMin) {
	std::vector<int> nums = {12, 3, 4, 5, 6, 3, 2, -10};
	int max = 0, min = 0;
	MaxAndMin(nums, max, min);
	ASSERT_EQ(Maximum(nums), max);
	ASSERT_EQ(Minimum(nums), min);	
};

TEST(OrderStatisticTest, RandomizedSelect) {
	std::vector<int> nums = {12, 3, 4, 5, 6, 3, 2, -10};
	const int K = nums.size();
	int Kth_num = RandomizedSelect(nums, 0, nums.size() - 1, K);
	std::sort(nums.begin(), nums.end());
	ASSERT_EQ(Kth_num, nums[K - 1]);
};

TEST(OrderStatisticTest, Select) {
	std::vector<int> nums = { 12, 3, 4, 5, 6, 3, 2, -10 };
	const int K = 2;
	int Kth_num = Select(nums, 0, nums.size() - 1, K);
	std::sort(nums.begin(), nums.end());
	ASSERT_EQ(Kth_num, nums[K - 1]);
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}