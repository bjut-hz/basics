package partitionEqualSubsetSum

/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such
that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

// backtrace, Time Limit Exceeded
func canPartition(nums []int) bool {
	totalSum := 0
	for _, v := range nums {
		totalSum += v
	}

	partSum := 0
	var solution func(int) bool
	solution = func(idx int) bool {
		// solution check
		if partSum == (totalSum - partSum) {
			return true
		}
		for i := idx; i < len(nums); i++ {
			partSum += nums[i]
			if solution(i+1) {
				return true
			}
			partSum -= nums[i]
		}
		return false
	}
	return solution(0)
}

// DP[i] i表示由数组子集求和的值
// DP: DP[i] = DP[i] || DP[i - nums[j]]   nums[j] <= i <=target
func canPartition1(nums []int) bool {
	totalSum := 0
	for _, v := range nums {
		totalSum += v
	}

	if totalSum % 2 != 0 {
		return false
	}

	target := totalSum / 2
	DP := make([]bool, target + 1, target + 1)
	DP[0] = true

	for _, v := range nums {
		for i := target; i >= v; i-- {
			DP[i] = DP[i] || DP[i-v]
		}
	}
	return DP[target]
}