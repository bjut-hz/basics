/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        const int N = nums.size();
        for(int i = 0; i < N; ++i) {
            if(i > 0 && nums[i- 1] == nums[i]) continue;
            for(int j = i + 1; j < N; ++j) {
                if(j > i + 1 && nums[j-1] == nums[j]) continue;
                                
                int m = j + 1, n = N - 1;
                while(m < n) {
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[m], nums[n]});
                        while(m < n && nums[n] == nums[n-1]) --n;
                        while(m < n && nums[m] == nums[m+1]) ++m;
                        --n;
                        --m;
                    } else if(sum > target) {
                        --n;
                    }else {
                        ++m;
                    }
                }
            }
        }
        
        return ans;
    }
};
// @lc code=end

