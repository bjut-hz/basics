package sort

func InsertionSort(nums []int) {
	N := len(nums)
	if 0 == N {
		return
	}

	for P := 1; P < N; P++ {
		tmp := nums[P]
		j := 0
		for j = P; j > 0 && tmp < nums[j-1]; j-- {
			nums[j] = nums[j-1]
		}
		nums[j] = tmp
	}
}