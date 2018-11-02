package longestIncreasingSubsequence


/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

// 启发：对DP进行遍历求解
// DP[i] = max(DP[i], Dp[j] + 1) when nums[i] > nums[j] && 0 <= j < i
func lengthOfLIS(nums []int) int {
	if 0 == len(nums) {
		return 0
	}

	N := len(nums)
	result := 0
	DP := make([]int, N)
	for i := range DP {
		DP[i] = 1
		result = 1
	}


	for i := 1; i < N; i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				if DP[j] + 1 > DP[i] {
					DP[i] = DP[j] + 1
				}
			}
		}
		if DP[i] > result {
			result = DP[i]
		}
	}

	return result
}


/*
复杂度
O(NlgN),O(N)

思路
因为要找increasing的序列，所以先遍历数组。再用二分法找当前值应该在排好序的数组中的插入位置。

对于排好序的数组，尽量用较小的值去替换已经排好序的数组中的值。因为要找的是最长的序列，所以每次将排好序的数组中替换成已经排好序的，会能保证得到的结果是最长的。
*/
func lengthOfLIS1(nums []int) int {
	binary := func(a []int, left, right int, val int) int {
		for left <= right {
			mid := left + (right - left) / 2
			if a[mid] >= val {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
		return left
	}

	length := 0
	a := make([]int, len(nums))
	for _, v := range nums {
		index := binary(a, 0, length - 1, v)
		a[index] = v

		if length == index {
			length++
		}
	}
	return length
}