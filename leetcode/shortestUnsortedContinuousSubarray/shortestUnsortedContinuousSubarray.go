package shortestUnsortedContinuousSubarray

import "sort"

/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order,
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

func findUnsortedSubarray(nums []int) int {
	N := len(nums)
	tmpArr := make([]int, N, N)
	copy(tmpArr, nums)

	sort.Ints(tmpArr)

	left := 0
	right := N - 1
	for ; left < N && nums[left] == tmpArr[left]; left++ {}
	for ; right >= 0 && nums[right] == tmpArr[right]; right-- {}
	if right > left {
		return right - left + 1
	}
	return 0
}