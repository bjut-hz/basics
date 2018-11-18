package permutations

/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


func permute(nums []int) [][]int {
	if 0 == len(nums) { return [][]int{} }

	result := make([][]int, 0, len(nums) * len(nums))
	backTrack(nums, make([]bool, len(nums)), []int{}, &result)

	return result
}

func backTrack(nums []int, visited []bool, out []int, result *[][]int) {
	if len(out) == len(nums) {
		tmp := make([]int, len(out))
		copy(tmp, out)

		*result = append(*result, tmp)
		return
	}

	for i := 0; i < len(nums); i++ {
		if !visited[i] {
			out = append(out, nums[i])
			visited[i] = true

			backTrack(nums, visited, out, result)

			out = (out)[0:len(out) - 1]
			visited[i] = false
		}
	}
}