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
    /**
        dp[i][j]表示s[0,i-1]与p[0,j-1]是否match
        dp[i][j] = dp[i-1][j-1], if p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.')

        如果p[j-1] == '*', 那么可以分成三种情况：
        1、匹配0次：    dp[i][j] = dp[i][j-2]
        2、匹配1次：    dp[i][j] = dp[i][j-1]， (s[i-1] == p[j-2] || p[j-2] == '.')
        3、至少1次：   dp[i][j] = dp[i-1][j]，(s[i-1] == p[j-2] || p[j-2] == '.') 公式解释:如果dp[i-1][j]为真的话，说明*已经进行了匹配(0,1多次都有可能)，此时再多加一次匹配   

        2,3可以合并
    */
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(j > 1 && p[j-1] == '*' ) {
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

