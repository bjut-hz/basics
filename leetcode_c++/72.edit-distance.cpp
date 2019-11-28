/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (40.27%)
 * Likes:    2726
 * Dislikes: 42
 * Total Accepted:    209.5K
 * Total Submissions: 519.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // // 对于word1的位置i, word2的位置j, 
    // // 如果两者相等,则i+1, j+1,此时不用做操作,
    // // 若不想等,有三种种可能的处理方法,都需要1次操作
    // // 把word1里的字符更改,那么也是i+1, j+1
    // // 在word1里增加一个字符word2[j],那么是j+1,i不变
    // // 直接删除word1[i],那么是i+1, j
    // int minDistance(string word1, string word2) {
    //     vector<vector<int>> mem(word1.size(), vector<int>(word2.size()));
    //     return helper(word1, word2, 0, 0, mem);
    // }

    // int helper(string& word1, string& word2, int i, int j, vector<vector<int>>& mem) {
    //     if(i == word1.size()) return int(word2.size()) - j;
    //     if(j == word2.size()) return int(word1.size()) - i;

    //     if(mem[i][j] > 0) return mem[i][j];
    //     int res = 0;
    //     if(word1[i] == word2[j]) {
    //         return helper(word1, word2, i+1, j+1, mem);
    //     } else {
    //         int changeCnt = 1 + helper(word1, word2, i + 1, j + 1, mem);
    //         int insertCnt = 1 + helper(word1, word2, i, j + 1, mem);
    //         int removeCnt = 1 + helper(word1, word2, i + 1, j, mem);
    //         res = min(changeCnt, min(insertCnt, removeCnt));
    //     }
    //     mem[i][j] = res;
    //     return res;
    // }

    // 上述方法就是带备忘录的递归方法,其实就是动态规划
    // dp[i][j] 表示word1的i位置与word2的j位置子串转化需要的最少次数
    // dp[i][j] = dp[i-1][j-1] 如果word1[i] == word2[j], 否则
    // dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();

        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool same = false;
        for(int i = 0; i < m; ++i) {
            if(word1[i] == word2[0]) {
                same = true;
            } 
            dp[i][0] = same ? i : i + 1;
        }
        same = false;
        for(int j = 0; j < n; ++j) {
            if(word1[0] == word2[j]) {
                same = true;
            } 
            dp[0][j] = same ? j : j + 1;
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

