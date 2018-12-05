package longestValidParentheses

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

// brute force: Time Limit Exceeded
func longestValidParentheses(s string) int {
	isValid := func (str string) bool {
		length := len(str)
		if length & 1 == 0x1 {
			return false
		}

		stack := 0
		for i := 0; i < len(str); i++ {
			if str[i] == '(' {
				stack++
			} else {
				if stack <= 0 { return false }
				stack--
			}
		}
		return stack == 0
	}

	maxLen := 0
	for i := 0; i < len(s); i++ {
		for j := i + 2; j <= len(s); j = j + 2 {
			if isValid(s[i:j]) {
				l := j - i
				if l > maxLen {
					maxLen = l
				}
			}
		}
	}

	return maxLen
}


// DP: ith element of DP represents the length of the longest valid substring ending at ith index.
// valid substrings must end with ')'.
// DP[i] = DP[i-2] + 2, if s[i] == ')' and s[i-1] == '('
// DP[i] = DP[i-1] + DP[i - DP[i-1] - 2] + 2, if s[i] == s[i-1] == ')' and s[i - DP[i-1]- 1] == '('
func longestValidParentheses1(s string) int {
	maxLen := 0
	DP := make([]int, len(s))
	for i := 1; i < len(s); i++ {
		if s[i] == ')' {
			if s[i-1] == '(' {
				if i >= 2 {
					DP[i] = DP[i-2] + 2
				} else {
					DP[i] = 2
				}
			} else if i - DP[i-1] > 0 && s[i - DP[i-1] - 1] == '(' {
				if i - DP[i-1] >= 2 {
					DP[i] = DP[i-1] + DP[i - DP[i-1] - 2] + 2
				} else {
					DP[i] = DP[i-1] + 2
				}
			}

			if DP[i] > maxLen {
				maxLen = DP[i]
			}
		}
	}
	return maxLen
}