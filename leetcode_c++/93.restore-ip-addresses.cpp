/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.56%)
 * Likes:    954
 * Dislikes: 422
 * Total Accepted:    168.3K
 * Total Submissions: 501.4K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        helper(ans, s, "", 4);
        return ans;
    }

    void helper(vector<string>& ans, string str, string out, int K) {
        if(0 == K) {
            if(str.empty()) {
                ans.push_back(out);
            }
            return;
        }

        for(int i = 1; i <= 3; ++i) {
            if(str.size() >= i && isValid(str.substr(0, i))) {
                if(K == 1) {
                    helper(ans, str.substr(i), out + str.substr(0, i), K-1);
                } else {
                    helper(ans, str.substr(i), out + str.substr(0, i) + ".", K-1);
                }
            }
        }
    }

    bool isValid(string str) {
        if(str.empty() || str.size() > 3 || (str.size() > 1 && str[0] == '0')) return false;
        int num = atoi(str.c_str());
        return num >= 0 && num <= 255;
    }
};
// @lc code=end

