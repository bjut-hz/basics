package subsets

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

func backTrack(nums []int, out []int, level int, result *[][]int) {
	tmp := make([]int, len(out))
	copy(tmp, out)
	*result = append(*result, tmp)

	for i := level; i < len(nums); i++ {
		out = append(out, nums[i])
		backTrack(nums, out, i + 1, result)
		out = out[0:len(out)-1]
	}
}

func dfs(nums []int, out []int, level int, result *[][]int) {
	if level == len(nums) {
		tmp := make([]int, len(out))
		copy(tmp, out)
		*result = append(*result, tmp)
		return
	}

	dfs(nums, out, level + 1, result)
	out = append(out, nums[level])
	dfs(nums, out, level + 1, result)
	out = out[0:len(out)-1]
}

func subsets(nums []int) [][]int {
	result := make([][]int, 0, 1 << uint32(len(nums)))
	dfs(nums, []int{}, 0, &result)

	return result
}

// iteratively
func subsets1(nums []int) [][]int {
	result := make([][]int, 1, 1 << uint32(len(nums)))

	// every iteration, len(result) will be doubled
	for i := 0; i < len(nums); i++ {
		size := len(result)
		for j := 0; j < size; j++ {
			// should use copy, or num in slice will be modified
			tmp := make([]int, len(result[j]))
			copy(tmp, result[j])
			result = append(result, tmp)
			result[len(result)-1] = append(result[len(result)-1], nums[i])
		}
	}

	return result
}

// bitmap
func subsets2(nums []int) [][]int {
	result := make([][]int, 1 << uint32(len(nums)))

	for i := 0; i < len(result); i++ {
		for j := 0; j < len(nums); j++ {
			if (uint32(i) >> uint32(j)) & 1 == 1 {
				result[i] = append(result[i], nums[j])
			}
		}
	}

	return result
}