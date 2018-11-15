package letterCombinationsOfAPhoneNumber

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

func letterCombinations(digits string) []string {
	if 0 == len(digits) {
		return []string{}
	}

	dict := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	result := make([]string, 0)
	dfs(digits, 0, dict, "", &result)

	return result
}

func dfs(digits string, level int, dict []string, out string, soltions *[]string) {
	if level == len(digits) {
		*soltions = append(*soltions, out)
		return
	}

	str := dict[digits[level] - '0']
	for i := 0; i < len(str); i++ {
		dfs(digits, level+1, dict, out + str[i:i+1], soltions)
	}
}

// iteratively
func letterCombinations1(digits string) []string {
	if 0 == len(digits) {
		return []string{}
	}

	dict := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	result := make([]string, 1)
	for i := 0; i < len(digits); i++ {
		// use tmp simulate and result stack
		tmp := make([]string, 0)
		str := dict[digits[i] - '0']
		for j := 0; j < len(str); j++ {
			for _, s := range result {
				tmp = append(tmp, s + str[j:j+1])
			}
		}
		result = tmp
	}

	return result
}