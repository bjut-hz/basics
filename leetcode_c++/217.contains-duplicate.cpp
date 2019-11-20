/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto& num : nums) {
            if(s.count(num)) return true;
            s.insert(num);
        }
        return false;
    }
};
// @lc code=end

