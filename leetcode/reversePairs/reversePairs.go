package reversePairs




func solution(nums []int, tmp []int) int {
	if 0 == len(nums) || 1 == len(nums) {
		return 0
	}

	center := len(nums) / 2

	slice1 := nums[0:center]
	slice2 := nums[center:]

	count1 := solution(slice1, tmp)
	count2 := solution(slice2, tmp)

	count3 := 0
	for _, v := range slice2 {
		target := 2 * v
		left, right := 0, len(slice1) - 1
		for left <= right {
			mid := left + (right - left) / 2
			if slice1[mid] > target {
				var index int = 0
				// find the proper index
				for index = mid; index >= 0; index-- {
					if slice1[index] <= target {
						break
					}
				}

				count3 = count3 + len(slice1) - index - 1
				break
			} else {
				left = mid + 1
			}
		}
	}

	merge(slice1, slice2, tmp)
	// copy back to nums
	copy(nums[0:], tmp[0:len(nums)])

	return count1 + count2 + count3
}

func reversePairs(nums []int) int {
	tmpArray := make([]int, len(nums), len(nums))
	return solution(nums, tmpArray)
}

