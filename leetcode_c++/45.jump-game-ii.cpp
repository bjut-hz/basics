/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        int cur = 0;
        int res = 0;
        int i = 0; // 注意此处i的妙用,一个变量就记录了遍历的位置，直接遍历完了这次跳跃的所有范围内的数字
        while(cur < N - 1) {
            ++res;

            int pre = cur;
            for(; i <= pre; ++i) {
                cur = max(cur, nums[i] + i);
            }
            if(pre == cur) return -1;
        }

        return res;
    }
};
// @lc code=end

