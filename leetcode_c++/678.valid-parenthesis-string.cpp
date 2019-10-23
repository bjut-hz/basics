/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
    // // brute force
    // bool helper(string& s, int start, int cnt) {
    //     if(cnt < 0) return false;
    //     for(int i = start; i < s.size(); ++i) {
    //         if(s[i] == '(') {
    //             cnt++;
    //         } else if(s[i] == ')'){
    //             cnt--;
    //             if(cnt < 0) return false;
    //         } else {
    //             return helper(s, i + 1, cnt + 1) || helper(s, i + 1, cnt) || helper(s, i + 1, cnt - 1); // 把当前字符分别当成 '('、')'以及'求解'
    //         }
    //     }
    //     return 0 == cnt;
    // }
    // bool checkValidString(string s) {
    //     return helper(s, 0, 0);
    // }

    // 使用两个栈,分别存'('以及'*',当碰到')'时优先使用左括号匹配看是否会存在 "*("的情况
    bool checkValidString(string s) {
        vector<int> s1, s2;
        for(int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if(ch == '(') {
                s1.push_back(i);
            } else if(ch == '*') {
                s2.push_back(i);
            } else {
                if(s1.size() > 0) {
                    s1.pop_back();
                } else if(s2.size() > 0) {
                    s2.pop_back();
                } else {
                    return false;
                }
            }
        }

        while(!s1.empty() && !s2.empty()) {
            if(s2.back() < s1.back()) return false;
            s1.pop_back();
            s2.pop_back();
        }

        return s1.empty();
    }
};
// @lc code=end

