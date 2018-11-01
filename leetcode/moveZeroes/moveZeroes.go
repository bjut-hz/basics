package moveZeroes


/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

// two index:
func moveZeroes(nums []int)  {
	i, j := 0, 0
	N := len(nums)
	for i < N && j < N {
		if 0 == nums[i] {
			for ; j < N; j++ {
				if i < j && nums[j] != 0 {
					break
				}
			}
			if j < N {
				// swap
				nums[i] = nums[i] ^ nums[j]
				nums[j] = nums[i] ^ nums[j]
				nums[i] = nums[i] ^ nums[j]
			}
			j++ // point the next number
		}
		i++
	}
}