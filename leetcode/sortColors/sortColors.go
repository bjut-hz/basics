package sortColors

/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

// we can use counting sort, but need two way pass
func sortColors1(nums []int) {
	cnts := make([]int, 3)
	for i := 0; i < len(nums); i++ {
		cnts[nums[i]]++
	}

	idx := 0
	for i := 0; i < len(cnts); i++ {
		for j := 0; j < cnts[i]; j++ {
			nums[idx] = i
			idx++
		}
	}
}


func sortColors(nums []int) {
	if 0 == len(nums) { return }
	redIndex := 0
	blueIndex := len(nums) - 1

	for i := redIndex; i <= blueIndex; i++ {
		switch nums[i] {
		case 0: {
			nums[redIndex], nums[i] = nums[i], nums[redIndex]
			redIndex++
		}
		case 2: {
			nums[blueIndex], nums[i] = nums[i], nums[blueIndex]
			blueIndex--
			i--
		}
		}
	}
}