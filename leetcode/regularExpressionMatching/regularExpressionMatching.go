package regularExpressionMatching

/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

func isMatch(s string, p string) bool {
	if len(p) == 0 { return 0 == len(s) }

	if len(p) == 1 {
		return len(s) == 1 && (s[0] == p[0] || p[0] == '.')
	}

	if p[1] != '*' {
		if 0 == len(s) { return false }
		return (s[0] == p[0] || p[0] == '.') && isMatch(s[1:], p[1:])
	}

	// p[1] == '*', match one or more
	for len(s) != 0 && (s[0] == p[0] || p[0] == '.') {
		if isMatch(s, p[2:]) { return true }
		s = s[1:]
	}

	// match zero
	return isMatch(s, p[2:])
}

// DP
// P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
// P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
// P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

func isMatch1(s string, p string) bool {
	DP := make([][]bool, len(s) + 1)
	for i := 0; i < len(DP); i++ {
		DP[i] = make([]bool, len(p) + 1)
	}

	DP[0][0] = true
	for i := 0; i <= len(s); i++ {
		for j := 1; j <= len(p); j++ {
			if j >= 2 && p[j-1] == '*' {
				DP[i][j] = DP[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && DP[i-1][j])
			} else {
				DP[i][j] = i > 0 && DP[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
			}
		}
	}

	return DP[len(s)][len(p)]
}