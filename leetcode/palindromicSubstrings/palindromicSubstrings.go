package palindromicSubstrings

/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

func countSubstrings(s string) int {
	N := len(s)
	DP := make([][]bool, N)
	for i := 0; i < N; i++ {
		DP[i] = make([]bool, N)
		DP[i][i] = true
	}

	res := N
	for j := 1; j < N; j++ {
		for i := 0; i < j; i++ {
			DP[i][j] = (s[i] == s[j]) && ( (j - i) <= 2 || DP[i+1][j-1])
			if DP[i][j] {
				res++
			}
		}
	}
	return res
}