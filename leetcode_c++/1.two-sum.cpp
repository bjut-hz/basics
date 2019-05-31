/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        result.reserve(2);

        map<int, int> dict;
        for(size_t i = 0; i < nums.size(); ++i) {
            dict[nums[i]] = i;
        }

        for(size_t i = 0; i < nums.size(); ++i) {
            if(dict.find(target - nums[i]) != dict.end() && dict[target - nums[i]] != i) {
                result.emplace_back(i);
                result.emplace_back(dict[target - nums[i]]);
                break;
            }
        }

        return result;
    }
};

