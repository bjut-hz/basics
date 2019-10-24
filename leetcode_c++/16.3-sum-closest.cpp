/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0; i < N; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = N - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ret = sum;
                }
                if(sum == target) {
                    return sum;
                } else if(sum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

