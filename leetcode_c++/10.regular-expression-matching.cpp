/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start


class Solution {
public:

    // /*
    // - 若p为空，若s也为空，返回true，反之返回false。
    // - 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false。
    // - 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。
    // - 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括p[0]为点），调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配），若匹配返回true，否则s去掉首字母（因为此时首字母匹配了，我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。
    // - 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，比如s="ab", p="a*b"，直接进入while循环后，我们发现"ab"和"b"不匹配，所以s变成"b"，那么此时跳出循环后，就到最后的return来比较"b"和"b"了，返回true。再举个例子，比如s="", p="a*"，由于s为空，不会进入任何的if和while，只能到最后的return来比较了，返回true，正确）。
    // */
    // bool isMatch(string s, string p) {
    //     if(p.empty()) return s.empty();
    //     if(1 == p.length()) {
    //         return 1 == s.length() && (s[0] == p[0] || '.' == p[0]);
    //     }

    //     if('*' != p[1]) {
    //         if(s.empty()) return false;
    //         return (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    //     }

    //     // p[1] == '*'
    //     while(!s.empty() && (s[0] == p[0] || '.' == p[0])) {
    //         if(isMatch(s, p.substr(2))) return true; // match zero
    //         s = s.substr(1);
    //     }

    //     return isMatch(s, p.substr(2));
    // }

    // recursive optimize
    
    // DP
    // dp[i][j]表示s[0,i)与p[0,j)是否match
    bool isMatch(string s, string p) {

    }
};
// @lc code=end

