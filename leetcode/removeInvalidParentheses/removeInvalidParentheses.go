package removeInvalidParentheses

/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/

func isValid(s string) bool {
	count := 0
	for _, ch := range s {
		if ch == '(' {
			count++
		} else if ch == ')' {
			count--
			if count < 0 {
				return false
			}
		}
	}

	return count == 0
}


func dfs(s string, set map[string]bool, maxLen *int) {
	N := len(s)
	if N < *maxLen {
		return
	}
	if isValid(s) {
		if _, ok := set[s]; !ok {
			if len(s) > *maxLen {
				*maxLen = N
			}
			set[s] = true
		} else {
			return
		}
	}

	for i := 0; i < N; i++ {
		if s[i] != '(' && s[i] != ')' {
			continue
		} else {
			dfs(s[0:i] + s[i+1:], set, maxLen)
		}
	}
}

func removeInvalidParentheses(s string) []string {
	set := make(map[string]bool, 10)
	maxLen := 0
	dfs(s, set, &maxLen)

	result := make([]string, 0, 10)
	for k := range set {
		if len(k) == maxLen {
			result = append(result, k)
		}
	}
	return result
}