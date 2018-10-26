package majorityElement

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

func majorityElement(nums []int) int {
	hashMap := make(map[int]int, len(nums))

	maxCount := 0
	result := 0
	for _, v := range nums {
		if _, ok := hashMap[v]; ok {
			hashMap[v]++
		} else {
			hashMap[v] = 1
		}
		if hashMap[v] > maxCount {
			maxCount = hashMap[v]
			result = v
		}
	}

	return result
}