package longestPalindromicSubstring

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

func longestPalindrome(s string) string {
	N := len(s)
	DP := make([][]bool, N)
	result := ""
	for i := 0; i < N; i++ {
		DP[i] = make([]bool, N)
		DP[i][i] = true
		result = s[i:i+1]
	}

	for j := 1; j < N; j++ {
		for i := 0; i < j; i++ {
			DP[i][j] = (s[i] == s[j]) && ( (j - i) <= 2 || DP[i+1][j-1])
			if DP[i][j] && (j - i + 1) > len(result) {
				result = s[i:j+1]
			}
		}
	}
	return result
}