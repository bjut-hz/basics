#include "segment_tree.h"
#include <assert.h>

int main() {
	std::vector<int> nums = {2, 1, 5, 3, 4};
	SegmentTree tree(nums);
	assert(tree.RangeQuery(0, 4) == 15);
	tree.Update(0, 0);
	assert(tree.RangeQuery(0, 4) == 13);
	assert(tree.RangeQuery(0, 2) == 6);
	assert(tree.RangeQuery(2, 4) == 12);
}