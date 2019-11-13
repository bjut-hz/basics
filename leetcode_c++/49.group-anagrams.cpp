/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort
        map<string, vector<string>> dict;
        for(auto& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& ele : dict) {
            res.push_back(ele.second);
        }
        return res;
    }
};
// @lc code=end

