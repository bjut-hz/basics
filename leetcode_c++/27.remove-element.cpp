/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		// 注意这个解法，保持一个正确的下标，然后遍历整个数组
		for (auto& num : nums) {
			if (num != val) {
				nums[i++] = num;
			}
		}
		return i;
	}
};

