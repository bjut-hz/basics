/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
	// int Partition(vector<int>& nums, int l, int r) {
	// 	auto x = nums[r];
	// 	int i = l - 1;

	// 	for (int j = l; j <= r - 1; ++j) {
	// 		if (nums[j] >= x) {
	// 			i = i + 1;
	// 			swap(nums[i], nums[j]);
	// 		}
	// 	}
	// 	swap(nums[i + 1], nums[r]); // left part is all biggger

	// 	return i + 1;
	// }

	// int findKth(vector<int>& nums, int l, int r, int K) {
	// 	int pos = Partition(nums, l, r);

	// 	int left_part_num = pos - l + 1;
	// 	if (left_part_num > K) {
	// 		return findKth(nums, l, pos - 1, K);
	// 	} else if (left_part_num < K) {
	// 		return findKth(nums, pos + 1, r, K - left_part_num);
	// 	} else {
	// 		return pos;
	// 	}
	// }

	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto& num : nums) {
			if (pq.empty()) {
				pq.push(num);
			} else {
				if (pq.size() == k) {
					if (num > pq.top()) {
						pq.pop();
					} else {
						continue;
					}
				}

				pq.push(num);
			}
		}

		return pq.top();
	}
};
// @lc code=end

