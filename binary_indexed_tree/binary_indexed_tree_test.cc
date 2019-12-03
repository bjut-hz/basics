#include "binary_indexed_tree.h"
#include <assert.h>

int main() {
	std::vector<int> nums = {1, 7, 3, 1, 5, 8};
	BinaryIndexededTree bit(nums);

	assert(bit.PrefixSum(3) == 12);
	assert(bit.RangeSum(0, 1) == 8);
	assert(bit.RangeSum(4, 5) == 13);

	bit.Add(0, 10);
	assert(bit.PrefixSum(3) == 22);
	assert(bit.RangeSum(0, 1) == 18);
	assert(bit.RangeSum(4, 5) == 13);
}