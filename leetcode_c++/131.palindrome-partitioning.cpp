/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string str) {
        if(str.empty()) return false;
        
        int i = 0;
        int j = str.size() - 1;
        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    
    void helper(vector<vector<string>>& res, vector<string>& out, int start, string& s) {
        if(start == s.size()) {
            if(out.size() > 0) {
                res.push_back(out);
            }
            return;
        }
        
        for(int i = start; i < s.size(); ++i) {
            string str = s.substr(start, i - start + 1);
            if(isPalindrome(str)) {
                out.push_back(str);
                helper(res, out, i + 1, s);
                out.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        helper(res, out, 0, s);
        
        return res;
    }
};
// @lc code=end

