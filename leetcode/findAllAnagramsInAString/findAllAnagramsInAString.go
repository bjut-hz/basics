package findAllAnagramsInAString

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

func findAnagrams(s string, p string) []int {
	N := len(s)
	M := len(p)
	result := make([]int, 0, 10)

	cache := make(map[byte]int, M)
	for i := 0; i < M; i++ {
		if _, ok := cache[p[i]]; ok {
			cache[p[i]] = cache[p[i]] + 1
		} else {
			cache[p[i]] = 0
		}
	}

	for i := 0; i <= (N - M); i++ {
		tmp := make(map[byte]int, M)
		for j := 0; j < M; j++ {
			if _, ok := cache[s[i+j]]; ok {
				if _, ok := tmp[s[i+j]]; ok {
					tmp[s[i+j]] = tmp[s[i+j]] + 1
				} else {
					tmp[s[i+j]] = 0
				}
			}
		}
		if len(tmp) == len(cache) {
			isSolution := true
			// compare map
			for k := range tmp {
				if tmp[k] != cache[k] {
					isSolution = false
					break
				}
			}
			if isSolution {
				result = append(result, i)
			}
		}
	}
	return result
}