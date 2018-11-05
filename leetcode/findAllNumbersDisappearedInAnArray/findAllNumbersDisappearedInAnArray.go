package findAllNumbersDisappearedInAnArray

/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

// 使用index跟value的关系
func findDisappearedNumbers(nums []int) []int {
	N := len(nums)
	result := make([]int, 0, N)
	for i := 0; i < N; i++ {
		// revert value
		idx := nums[i]
		if idx < 0 {
			idx = -idx
		}
		idx = idx - 1

		if nums[idx] > 0 {
			nums[idx] = -nums[idx]
		}
	}

	for i, v := range nums {
		if v > 0 {
			result = append(result, i+1)
		}
	}
	return result
}