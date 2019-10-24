/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        const int N = nums.size();
        for(int i = 0; i < N; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] > 0) break;

            // fix one, get the ramaining two
            int j = i + 1;
            int k = N - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    ++j;
                } else if(sum > 0) {
                    --k;
                } else {    
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // remove duplicate
                    while(j < k && nums[j] == nums[j+1]) ++j;
                    while(j < k && nums[k] == nums[k-1]) --k;
                    ++j;
                    --k;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

