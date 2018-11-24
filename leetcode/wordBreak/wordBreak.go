package wordBreak

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

func wordBreak(s string, wordDict []string) bool {
	dict := make(map[string]bool, len(wordDict))
	for i := 0; i < len(wordDict); i++ {
		dict[wordDict[i]] = true
	}

	DP := make([]bool, len(s))
	DP[0] = dict[s[0:1]]
	for i := 0; i < len(s); i++ {
		for j := 0; j < i; j++ {
			DP[i] = DP[i] || dict[s[0:i+1]] || (DP[j] && dict[s[j+1:i+1]])
		}
	}
	return DP[len(s) - 1]
}