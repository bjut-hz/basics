package reversePairs

import (
	"testing"
	"fmt"
)

func TestTwoSum(t *testing.T) {
	arr := [...]int{3, 2, 33, 4, 4444, 1, 1, 2, 3, 4, 4, 33, 55, 6}

	fmt.Println(arr)

	MergeSort(arr[0:])
	fmt.Println(arr)
}