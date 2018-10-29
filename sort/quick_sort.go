package sort

func QuickSort(nums []int)  {
	N := len(nums)
	if 0 == N || 1 == N {
		return
	}

	pivot := nums[0]
	i := 0
	j := N
	for {
		for {
			// should add here. or it will be in endless loop if all element is same
			i++
			if i < N && nums[i] < pivot {} else {break}
		}
		for {
			j--
			if j > 0 && nums[j] > pivot {} else {break}
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
	nums[0] = nums[j]
	nums[j] = pivot

	QuickSort(nums[0:j])
	QuickSort(nums[j+1:]) // should use j+1, or it will be in endless loop when j = 0
}