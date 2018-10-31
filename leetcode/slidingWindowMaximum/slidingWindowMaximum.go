package slidingWindowMaximum

import "container/list"

/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very
right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/


func maxSlidingWindow(nums []int, k int) []int {
	if nil == nums || 0 == len(nums) {
		return nums
	}

	N := len(nums)
	result := make([]int, N - k + 1)

	// save the num of nums in descending order
	// q save the index of num
	q := list.New()
	for i := 0; i < N; i++ {
		// remove the left most element
		if 0 != q.Len() && q.Front().Value == (i - k) {
			e := q.Front()
			q.Remove(e)
		}

		// remove min num in q and put new number in the q
		for 0 != q.Len() && nums[i] >= nums[q.Back().Value.(int)] {
			e := q.Back()
			q.Remove(e)
		}
		q.PushBack(i)

		if i + 1 >= k {
			result[i+1-k] = nums[q.Front().Value.(int)]
		}
	}

	return result
}