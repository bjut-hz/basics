/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> dict;
		for (int i = 0; i < nums.size(); ++i) {
			dict[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); ++i) {
			auto iter = dict.find(target - nums[i]);
			if (iter != dict.end() && i != iter->second) {
				return { i, dict[target - nums[i]] };
			}
		}
		return {};
	}
};
// @lc code=end

