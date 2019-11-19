/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;
		if((numerator ^ denominator) < 0) {
			sign = -1;
		}

		long long num = abs((long long)numerator);
		long long den = abs((long long)denominator);
		long long out = num / den;
		long long rem = num % den;

		string res = to_string(out);
		if(sign < 0 && (out > 0 || rem > 0)) {
			res = "-" + res;
		}
		if(rem == 0) return res;

		map<long long, int> m;
		res += ".";
		string s = "";
		int pos = 0;
		while(rem != 0) {
			// 如果找到了同样的余数，说明是个无限循环小数
			if(m.find(rem) != m.end()) {
				s.insert(m[rem], "(");
				s += ")";
				return res + s;
			}

			m[rem] = pos;
			s += to_string((rem * 10) / den);
			rem = (rem * 10) % den;
			++pos;
		}

		return res + s;
    }
};
// @lc code=end

