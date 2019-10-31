/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
class Solution {
public:
	// bool isAdditiveNumber(string num) {
	// 	for (int i = 0; i < num.size(); ++i) {
	// 		if (i >= 1 && '0' == num[0]) continue;
	// 		for (int j = i + 1; j < num.size(); ++j) {
	// 			if (j - i > 1 && '0' == num[i + 1]) continue;
	// 			string a_str = num.substr(0, i + 1);
	// 			string b_str = num.substr(i + 1, j - i);
	// 			long long a = stoll(a_str);
	// 			long long b = stoll(b_str);
    //             long long next = a + b;

	// 			string sum_str = a_str + b_str + to_string(next);
	// 			while (sum_str.size() < num.size()) {
	// 				a = b;
	// 				b = next;
    //                 next = a + b;
	// 				sum_str += to_string(next);
	// 			}

	// 			if (sum_str == num) return true;
	// 		}
	// 	}
	// 	return false;
	// }

	bool isAdditiveNumber(string num) {
		vector<long long> out;
		bool res = false;
		helper(num, out, 0, res);

		return res;
	}

	void helper(string& num, vector<long long>& out, int start, bool& res) {
		if (res == true) return;

		if (start == num.size()) {
			if (out.size() >= 3) {
				res = true;
			}
			return;
		}

		for (int i = start; i < num.size(); ++i) {
			string a_str = num.substr(start, i - start + 1);
			if ((a_str.size() > 1 && a_str[0] == '0') || a_str.size() > 19) {
				break;
			}

			long long cur_num = stoll(a_str);
			int n = out.size();
			if (n >= 2 && out[n - 1] + out[n - 2] != cur_num) {
				continue;
			}

			out.push_back(cur_num);
			helper(num, out, i + 1, res);
			out.pop_back();
		}
	}
};

// @lc code=end

