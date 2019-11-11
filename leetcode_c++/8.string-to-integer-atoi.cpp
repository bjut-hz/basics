/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;

        const int N = str.size();
        int i = 0;
        while(i < N && ' ' == str[i]) {i++;}
        if('-' == str[i]) {
            sign = -1;
            i++;
        } else if('+' == str[i]) {
            i++;
        }

        long long res = 0;
        while(i < N && isdigit(str[i])) {
            if(res * 10 > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (str[i] - '0');
            ++i;
        }

        res = sign * res;

        if(res < INT_MIN) return INT_MIN;
        if(res > INT_MAX) return INT_MAX;

        return res;
    }
};
// @lc code=end

