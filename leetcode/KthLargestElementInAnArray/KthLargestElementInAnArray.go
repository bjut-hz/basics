package KthLargestElementInAnArray

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/


// we can solve this based on quick sort
func findKthLargest(nums []int, k int) int {
	return findKth(nums, 0, len(nums), k)
}

// [left, right)
func findKth(nums []int, left, right, k int) int {
	pivot := nums[left]
	i := left
	j := right

	for {
		for {
			// should add here. or it will be in endless loop if all element is same
			i++
			if i < right && nums[i] > pivot {} else {break}
		}
		for {
			j--
			if j > left && nums[j] < pivot {} else {break}
		}

		if i < j {
			//swap
			tmp := nums[i]
			nums[i] = nums[j]
			nums[j] = tmp
		} else {
			break
		}
	}

	// swap pivot, and divide from pivot
	nums[left] = nums[j]
	nums[j] = pivot

	if j == k - 1 {
		return pivot
	} else if j < k - 1 {
		return findKth(nums, j + 1, right, k)
	} else if j > k - 1 {
		return findKth(nums, left, j, k)
	}
	return -1
}