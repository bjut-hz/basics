/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) {
			int sum = 0;
			for (auto& num : nums) {
				sum += num;
			}
			return sum;
		}

		sort(nums.begin(), nums.end());
		int sum = nums[0] + nums[1] + nums[2];
		int minDiff = abs(nums[0] + nums[1] + nums[2] - target);
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i - 1] == nums[i]) continue;

			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				int diff = nums[i] + nums[j] + nums[k] - target;
				if (abs(diff) < minDiff) {
					minDiff = abs(diff);
					sum = nums[i] + nums[j] + nums[k];
				}

				if (diff == 0) {
					return sum;
				} else if (diff < 0) {
					++j;
				} else {
					--k;
				}
			}
		}
		return sum;
	}
};

