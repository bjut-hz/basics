/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) return {};

		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		// 注意这里，size()返回的是size_t类型，是一个无符号的类型，当nums.size()<3时会越界
		for (auto i = 0; i < nums.size() - 3; ++i) {
			if (i > 0 && nums[i - 1] == nums[i]) continue; // remove duplicate
			// fix one, and find 3-sum now
			for (auto j = i + 1; j < nums.size() - 2; ++j) {
				// 注意这里，是要省略掉已经计算过的数字，减少重复计算
				if (j > i + 1 && nums[j - 1] == nums[j]) continue;

				int m = j + 1, n = nums.size() - 1;
				while (m < n) {
					if (nums[i] + nums[j] + nums[m] + nums[n] == target) {
						res.push_back({ nums[i], nums[j], nums[m], nums[n] });

						while (m < n && nums[m] == nums[m + 1]) { ++m; }
						while (m < n && nums[n] == nums[n - 1]) { --n; }
						
						++m;
						--n;
					} else if (nums[i] + nums[j] + nums[m] + nums[n] > target) {
						--n;
					} else {
						++m;
					}
				}
			}
		}

		return res;
	}
};

