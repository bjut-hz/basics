package generateParentheses

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

func generateParenthesis(n int) []string {
	if 0 == n {
		return []string{}
	}

	result := make([]string, 0)
	hashMap := make(map[string]bool)
	dfs(n, 1, "()", hashMap)

	for k := range hashMap {
		if len(k) == 2 * n {
			result = append(result, k)
		}
	}

	return result
}

func dfs(n int, level int, out string, result map[string]bool) {
	if _, ok := result[out]; ok {
		return
	}
	result[out] = true

	for i := level; i < n; i++ {
		for j := 0; j < len(out); j++ {
			if j == 0 {
				dfs(n, level+1, "()"+ out, result)
			}

			if j == len(out) - 1{
				dfs(n, level+1, out + "()", result)
			} else {
				dfs(n, level+1, out[0:j+1] + "()" + out[j+1:], result)
			}
		}
	}
}