/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
	using Operator = int(*)(int, int);
	static int add(int a, int b) {
		return a + b;
	}
	static int sub(int a, int b) {
		return a - b;
	}

	static int multi(int a, int b) {
		return a * b;
	}

	static int div(int a, int b) {
		return a / b;
	}

	int evalRPN(vector<string>& tokens) {
		map<string, Operator> dict;
		dict["+"] = &add;
		dict["-"] = &sub;
		dict["*"] = &multi;
		dict["/"] = &div;

		stack<int> stk;
		for (auto& str : tokens) {
			if (dict.count(str)) {
				int rhs = stk.top();
				stk.pop();
				int lhs = stk.top();
				stk.pop();


				stk.push(dict[str](lhs, rhs));
			} else {
				stk.push(stoi(str));
			}
		}

		return stk.top();
	}
};
// @lc code=end

