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

	cache := [256]int{}
	for i := 0; i < M; i++ {
		cache[p[i]]++
	}

	for i := 0; i <= (N-M); i++ {
		tmp := cache
		success := true
		for j := 0; j < M; j++ {
			tmp[s[i+j]]--
			if tmp[s[i+j]] < 0 {
				success = false
				break
			}
		}
		if success {
			result = append(result, i)
		}
	}

	return result
}

// 右侧加入了一个字符，左侧删除一个字符，对比是否相等
func findAnagrams1(s string, p string) []int {
	N := len(s)
	M := len(p)

	if N < M {
		return []int{}
	}

	result := make([]int, 0, 10)

	pCache := [256]int{}
	sCache := [256]int{}
	for i := 0; i < M; i++ {
		pCache[p[i]]++
		sCache[s[i]]++
	}
	if pCache == sCache {
		result = append(result, 0)
	}

	for i := M; i < N; i++ {
		sCache[s[i]]++
		sCache[s[i-M]]--
		if sCache == pCache {
			result = append(result, i-M+1)
		}
	}
	return result
}

// sliding window
func findAnagrams2(s string, p string) []int {
	N := len(s)
	M := len(p)

	if N < M {
		return []int{}
	}

	result := make([]int, 0, 10)

	left, right := 0, 0
	cnt := M

	pCache := [256]int{}
	for i := 0; i < M; i++ {
		pCache[p[i]]++
	}

	for right < N {
		if pCache[s[right]] >= 1 {
			cnt--
		}
		// enter window
		pCache[s[right]]--
		right++

		if 0 == cnt {
			result = append(result, left)
		}

		if right - left == M  {
			// 此时s[left]属于p字符串,那么应该cnt++
			if pCache[s[left]] >= 0 {
				cnt++
			}
			// left window
			pCache[s[left]]++
			left++
		}
	}
	return result
}