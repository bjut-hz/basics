package groupAnagrams

import "sort"

/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

func groupAnagrams(strs []string) [][]string {
	result := make([][]string, 0, len(strs))
	cache := make(map[string][]string, len(strs))
	for i := 0; i < len(strs); i++ {
		tmp := []byte(strs[i])
		sort.Slice(tmp, func(i, j int) bool {
			return tmp[i] <= tmp[j]
		})

		cache[string(tmp)] = append(cache[string(tmp)], strs[i])
	}

	for _, v := range cache {
		result = append(result, v)
	}

	return result
}

func groupAnagrams1(strs []string) [][]string {
	result := make([][]string, 0, len(strs))
	cache := make(map[string][]string, len(strs))

	for i := 0; i < len(strs); i++ {
		cnt := [26]int{}
		for j := 0; j < len(strs[i]); j++ {
			cnt[strs[i][j] - 'a']++
		}
		key := ""
		for _, v := range cnt {
			key += string(v)
		}
		cache[key] = append(cache[key], strs[i])
	}

	for _, v := range cache {
		result = append(result, v)
	}

	return result
}