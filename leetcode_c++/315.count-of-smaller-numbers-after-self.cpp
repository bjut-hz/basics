/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    /*
        将给定数组从最后一个开始，用二分法插入到一个新的数组，
        这样新数组就是有序的，那么此时该数字在新数组中的坐标就
        是原数组中其右边所有较小数字的个数
    */
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> tmp;
		vector<int> res(nums.size(), 0);
		for (int i = int(nums.size()) - 1; i >= 0; --i) {
			int left = 0;
			int right = tmp.size();
			int num = nums[i];

			while (left < right) {
				int mid = left + (right - left) / 2;
				// 找num的upper_bound
				if (num > tmp[mid]) {
					left = mid + 1;
				} else {
					right = mid;
				}
			}

			res[i] = right;
			tmp.insert(tmp.begin() + right, num);
		}

		return res;
	}
};
// @lc code=end

