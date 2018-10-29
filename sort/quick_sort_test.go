package sort

import (
	"testing"
	"fmt"
)

func TestQuickSortSort(t *testing.T) {
	nums := []int{2,1}
	QuickSort(nums)
	fmt.Println(nums)
}