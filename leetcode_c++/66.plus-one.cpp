/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return {};

        vector<int> res(digits.begin(), digits.end());
        const int N = res.size();
        int carry = 1;
        int i = N - 1;
        while(carry && i >= 0) {
            int tmp = carry;
            tmp = (res[i] + carry) / 10;
            res[i] = (res[i] + carry) % 10;
            carry = tmp;
            --i;
        }

        if(carry && i < 0) {
            res.insert(res.begin(), 1);
        }
        return res;
    }
};
// @lc code=end

