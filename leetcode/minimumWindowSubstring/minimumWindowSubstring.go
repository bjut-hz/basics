package minimumWindowSubstring

import "math"

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

func minWindow1(s string, t string) string {
	result := ""
	letterCount := make(map[byte]int, len(s))
	for i := 0; i < len(t); i++ {
		letterCount[t[i]]++
	}

	minLen := math.MaxInt64
	leftBorder := 0
	cnt := 0
	for i := 0; i < len(s); i++ {
		letterCount[s[i]]--
		if letterCount[s[i]] >= 0 { cnt++ }

		for cnt == len(t) {
			if minLen > (i - leftBorder + 1) {
				minLen = i - leftBorder + 1
				result = s[leftBorder:i+1]
			}

			letterCount[s[leftBorder]]++
			if letterCount[s[leftBorder]] > 0 { cnt-- }

			leftBorder++
		}
	}

	return result
}


func minWindow(s string, t string) string {
	result := ""
	letterCount := [128]int{}
	for i := 0; i < len(t); i++ {
		letterCount[t[i]]++
	}

	minLen := math.MaxInt64
	leftBorder := 0
	cnt := 0
	for i := 0; i < len(s); i++ {
		letterCount[s[i]]--
		if letterCount[s[i]] >= 0 { cnt++ }

		for cnt == len(t) {
			if minLen > (i - leftBorder + 1) {
				minLen = i - leftBorder + 1
				result = s[leftBorder:i+1]
			}

			letterCount[s[leftBorder]]++
			if letterCount[s[leftBorder]] > 0 { cnt-- }

			leftBorder++
		}
	}

	return result
}