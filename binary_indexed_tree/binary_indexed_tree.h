#ifndef BINARY_INDEXED_TREE_H
/* https://blog.csdn.net/Yaokai_AssultMaster/article/details/79492190 */

#include <vector>
#include <algorithm>

class BinaryIndexededTree {
public:
	explicit BinaryIndexededTree(std::vector<int>& nums) {
		bits_.resize(nums.size() + 1);
		copy(nums.begin(), nums.end(), bits_.begin() + 1);

		for(int i = 1; i < bits_.size(); ++i) {
			int j = i + LowBit(i);
			if(j < bits_.size()) {
				bits_[j] = bits_[j] + bits_[i];
			}
		}
	}

	void Add(int idx, int delta) {
		idx = idx + 1;
		while(idx < bits_.size()) {
			bits_[idx] += delta;
			idx += LowBit(idx);
		}
	}

	int RangeSum(int from, int to) {
		return PrefixSum(to) - PrefixSum(from - 1);
	}

	int PrefixSum(int to) {
		to = to + 1;
		int result = 0;
		while(to > 0) {
			result += bits_[to];
			to = to - LowBit(to);
		}
		return result;
	}
private:
	int LowBit(int i) {
		return i & (-i);
	}
private:
	std::vector<int> bits_;
};

#endif // BINARY_INDEXED_TREE_H