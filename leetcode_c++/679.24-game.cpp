/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
public:
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.begin(), nums.end());
        bool res = false;
        helper(arr, res);
        return res;
    }
    // 回溯的方法
    void helper(vector<double>& nums, bool& res) {
        if(res == true) return;
        if(1 == nums.size()) {
            if(abs(nums[0] - 24) < eps){
                res = true;
            }
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                double p = nums[i];
                double q = nums[j];

                vector<double> vec = {p + q, p - q, q - p, p * q};
                if(abs(p) > eps) vec.push_back(q / p);
                if(abs(q) > eps) vec.push_back(p / q);
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + j);

                for(auto d : vec) {
                    nums.push_back(d);
                    helper(nums, res);
                    nums.pop_back();
                }
                nums.insert(nums.begin() + j, q);
                nums.insert(nums.begin() + i, p);
            }
        }
    }
private:
    double eps = 0.0001;
};
// @lc code=end

