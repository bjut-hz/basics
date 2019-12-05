/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (35.19%)
 * Likes:    963
 * Dislikes: 165
 * Total Accepted:    141.1K
 * Total Submissions: 400.5K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;

        map<char, int> priority;
        priority['+'] = 0;
        priority['-'] = 0;
        priority['*'] = 1;
        priority['/'] = 1;


        stack<int> num_stk;
        stack<char> op_stk;

        int i = 0;
        while(i < s.size()) {
            if(s[i] == ' ') {
                i++;
                continue;
            }

            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                num_stk.push(num);
            } else {
                if(op_stk.empty() || priority[s[i]] > priority[op_stk.top()]) {
                    op_stk.push(s[i]);
                    i++;
                } else {
                    int rhs = num_stk.top();
                    num_stk.pop();
                    int lhs = num_stk.top();
                    num_stk.pop();

                    char op = op_stk.top();
                    op_stk.pop();

                    if(op == '+') {
                        num_stk.push(lhs + rhs);
                    } else if(op == '-') {
                        num_stk.push(lhs - rhs);
                    } else if(op == '*') {
                        num_stk.push(lhs * rhs);
                    } else {
                        num_stk.push(lhs / rhs);
                    }
                }
            }
        }

        while (!op_stk.empty()) {
			int rhs = num_stk.top();
			num_stk.pop();
			int lhs = num_stk.top();
			num_stk.pop();

			char op = op_stk.top();
			op_stk.pop();

			if (op == '+') {
				num_stk.push(lhs + rhs);
			} else if (op == '-') {
				num_stk.push(lhs - rhs);
			} else if (op == '*') {
				num_stk.push(lhs * rhs);
			} else {
				num_stk.push(lhs / rhs);
			}
		}

        return num_stk.top();
    }
};
// @lc code=end

