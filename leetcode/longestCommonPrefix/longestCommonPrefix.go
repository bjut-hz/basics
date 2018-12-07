package longestCommonPrefix

import "strings"

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

// my original solution
func longestCommonPrefix(strs []string) string {
	if 0 == len(strs) { return "" }

	minStr := strs[0]
	for i := 0; i < len(strs); i++ {
		if len(strs[i]) < len(minStr) {
			minStr = strs[i]
		}
	}

	res := ""
	for i := 0; i < len(minStr); i++ {
		tmp := minStr[0:i+1]
		j := 0
		for j = 0; j < len(strs); j++ {
			if strs[j][0:i+1] != tmp {
				break
			}
		}

		if j == len(strs) { res = tmp }
	}

	return res
}

// Time: O(S), S is sum of all characters in all strings
// Space: O(1)
// Horizontal scanning
func longestCommonPrefix1(strs []string) string {
	N := len(strs)
	if 0 == len(strs) { return "" }

	prefix := strs[0]

	for i := 1; i < N; i++ {
		for strings.Index(strs[i], prefix) != 0 {
			prefix = prefix[0:len(prefix) - 1]
			if 0 == len(prefix) { return ""}
		}
	}
	return prefix
}

// Time: O(S), S is sum of all characters in all strings
// Space: O(1)
// vertical scanning: consider strs as an two-dimensional array
func longestCommonPrefix2(strs []string) string {
	N := len(strs)
	if 0 == len(strs) { return "" }

	i := 0
	for i = 0; i < len(strs[0]); i++ {
		for j := 0; j < N; j++ {
			if i == len(strs[j]) || strs[0][i] != strs[j][i] {
				return strs[0][0:i]
			}
		}
	}

	return strs[0][0:i]
}

// divide and conquer
func longestCommonPrefix3(strs []string) string {
	N := len(strs)
	if 0 == N {
		return ""
	}
	if 1 == N { return strs[0] }

	mid := N / 2
	left := longestCommonPrefix3(strs[0:mid])
	right := longestCommonPrefix3(strs[mid:])

	i := 0
	for ; i < len(left) && i < len(right) && left[i] == right[i]; i++ {}
	return left[0:i]
}


// use binary search

// trie tree