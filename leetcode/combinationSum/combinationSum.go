package combinationSum

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

func combinationSum(candidates []int, target int) [][]int {
	if 0 == len(candidates) { return [][]int{} }

	var result [][]int
	var dfs func(int, int, []int)
	dfs = func(cur int, sum int, out []int) {
		if sum > target { return }

		if sum == target {
			tmp := make([]int, len(out))
			copy(tmp, out)
			result = append(result, tmp)
			return
		}

		for i := cur; i < len(candidates); i++ {
			out = append(out, candidates[i])
			dfs(i, sum + candidates[i], out)
			out = (out)[0:len(out) - 1]
		}
	}

	dfs(0, 0, []int{})

	return result
}