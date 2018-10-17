package reversePairs

func merge(A []int, B []int, tmp[]int) {
	// array index
	var i, j, m = 0, 0, 0

	for i < len(A) && j < len(B) {
		if A[i] < B[j] {
			tmp[m] = A[i]
			i++
		} else {
			tmp[m] = B[j]
			j++
		}
		m++
	}

	if i < len(A) {
		copy(tmp[m:], A[i:])
	}

	if j < len(B) {
		copy(tmp[m:], B[j:])
	}
}


func mergeSort(A []int, tmp []int) {
	if 0 == len(A) || 1 == len(A) {
		return
	}

	center := len(A) / 2

	// there are log(N) slice variable
	mergeSort(A[0:center], tmp)
	mergeSort(A[center:], tmp)
	merge(A[0:center], A[center:], tmp)

	// copy back to A
	copy(A[0:], tmp[0:len(A)])
}

func MergeSort(A []int) {
	// use global tmp array, only one tmp array used at same time
	tmp := make([]int, len(A), len(A))
	mergeSort(A, tmp)
}