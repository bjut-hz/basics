/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		if (nums.size() == 0) return {};

		vector<vector<int>> result;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) { // prune
				break;
			}

			if (i > 0 && nums[i] == nums[i - 1]) { continue; }

			int target = 0 - nums[i];
			// fix one and find remaining two number
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[j] + nums[k] == target) {
					result.push_back({ nums[i], nums[j], nums[k] });
					// remove duplicate
					while (j < k && nums[j] == nums[j + 1]) { ++j; }
					while (j < k && nums[k] == nums[k - 1]) { --k; }
					++j;
					--k;
				} else if (nums[j] + nums[k] < target) {
					++j;
				} else {
					--k;
				}
			}
		}
		return result;
	}
};

