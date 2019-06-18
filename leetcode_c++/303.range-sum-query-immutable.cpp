/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
class NumArray {
private:
	vector<int> acc; // 记录从0开始i的和
public:
	NumArray(vector<int>& nums) {
		int sum = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			acc.push_back(sum);
		}
	}

	int sumRange(int i, int j) {
		if (i >= 1) {
			return acc[j] - acc[i-1];
		}
		else {
			return acc[j];
		}
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

