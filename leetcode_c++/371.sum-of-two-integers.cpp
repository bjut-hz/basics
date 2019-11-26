/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.76%)
 * Likes:    913
 * Dislikes: 1713
 * Total Accepted:    155.5K
 * Total Submissions: 306.4K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        while(b != 0) {
            sum = a ^ b;
            // leetcode编译器不能对负数进行左移,强制让高位为0
            carry = (a&b&0x7fffffff) << 1;
            a = sum;
            b = carry;
        }
        return sum;
    }
};
// @lc code=end

