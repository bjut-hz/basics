/*
 * @lc app=leetcode id=761 lang=cpp
 *
 * [761] Special Binary String
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string S) {
        int i = 0;
        int cnt = 0;
        vector<string> vec;
        for(int j = 0; j < S.size(); ++j) {
            cnt = S[j] == '1' ? ++cnt : --cnt;
            if(cnt == 0) { // find a valid substr
                vec.push_back('1' + makeLargestSpecial(S.substr(i+1, j - i - 1)) + '0'); // 对合法的字符串内部进行求解
                i = j + 1;
            }
        }

        sort(vec.begin(), vec.end(), greater<string>()); // 排序，比较大的放在前面

        string res; 
        for(auto& str : vec) { // 组合所有合法拆解的子字符串得到最终解
            res += str;
        }
        return res;
    }
};
// @lc code=end

