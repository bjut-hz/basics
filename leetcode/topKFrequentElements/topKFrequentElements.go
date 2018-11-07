package topKFrequentElements

/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

func topKFrequent(nums []int, k int) []int {
	N := len(nums)
	hashMap := make(map[int]int, N)
	for _, v := range nums {
		if _, ok := hashMap[v]; !ok {
			hashMap[v] = 0
		}
		hashMap[v]++
	}

	// bucket sort
	buckets := make([][]*int, N + 1)

	for num, times := range hashMap {
		tmp := num
		buckets[times] = append(buckets[times], &tmp)
	}

	result := make([]int, k)
	i := 0
	for j := N; j >= 0; j-- {
		for _, v := range buckets[j] {
			if nil != v {
				if i < k {
					result[i] = *v
					i++
				} else {
					return result
				}
			}
		}
	}

	return result
}