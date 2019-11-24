/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.87%)
 * Likes:    362
 * Dislikes: 1233
 * Total Accepted:    214.3K
 * Total Submissions: 511.6K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 * Example 1:
 * 
 * 
 * Input: 27
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: true
 * 
 * Example 4:
 * 
 * 
 * Input: 45
 * Output: false
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 */

// @lc code=start
class Solution {
public:
    // bool isPowerOfThree(int n) {
    //     while(n) {
    //         if(1 == n) return true;
    //         if(n % 3) {
    //             return false;
    //         }
    //         n /= 3;
    //     }
    //     return false;
    // }

    // 换底公式 log a(b) = log c(b) / log c(a) 
    // 判断a是不是整数: int(a) - a == 0
    bool isPowerOfThree(int n) {
        return n > 0 && (  int(log10(n) / log10(3)) - (log10(n) / log10(3)) == 0  );
    }
};
// @lc code=end

