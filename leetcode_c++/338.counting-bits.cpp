/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (66.08%)
 * Likes:    1773
 * Dislikes: 123
 * Total Accepted:    203.3K
 * Total Submissions: 307.5K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */

// @lc code=start
class Solution {
public:
    // 找规律
    // 规律1. [pow(2, i), pow(2, i + 1))的关系
    // vector<int> countBits(int num) {
    //     if(num == 0) return {0};

    //     vector<int> res = {0, 1};
    //     res.reserve(num + 1);

    //     int i = 1;
    //     while(res.size() < num + 1) {
    //         int lower = pow(2, i);
    //         int upper = pow(2, i + 1);
    //         int idx = 0;
    //         for(; lower < upper && res.size() < num + 1; ++lower) {
    //             res.push_back(res[idx++] + 1);
    //         }
    //         i++;
    //     }
    //     return res;
    // }

    // 使用 i & (i-1)
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 1; i <= num; ++i) {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};
// @lc code=end

