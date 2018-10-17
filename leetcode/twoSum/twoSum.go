package twoSum

func twoSum(nums []int, target int) []int {
	result := make([]int, 0, 2)
	dic := make(map[int]int, len(nums))

	for i, v := range nums {
		dic[v] = i
	}

	for i, v := range nums {
		if i2, ok := dic[target - v]; ok && i != i2 {
			result = append(result, i, i2)
			return result
		}
	}

	return result
}

