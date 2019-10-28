/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
class Solution {
public:
    vector<int> beautifulArray(int N) {
        if(1 == N) return {1};

        auto left = beautifulArray(N / 2);
        auto right = beautifulArray((N + 1) / 2);

        vector<int> res;
        for(auto& num : left) {
            res.push_back(2 * num);
        }

        for(auto& num : right) {
            res.push_back(2 * num - 1);
        }
        return res;
    }
};
// @lc code=end

