/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string a_b = to_string(a) + to_string(b);
            string b_a = to_string(b) + to_string(a);
            return a_b > b_a;
        });

        string res;
        for(auto& num : nums) {
            res += to_string(num);
        }
        return res[0] == '0' ? "0" : res;
    }
};
// @lc code=end

