/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        while(num >= 2) {
            if(num % 2 == 0) {
                num /= 2;
            } else if(num % 3 == 0) {
                num /= 3;
            } else if(num % 5 == 0) {
                num /= 5;
            } else  {
                break;
            }
        }
        return num == 1;
    }
};
// @lc code=end

