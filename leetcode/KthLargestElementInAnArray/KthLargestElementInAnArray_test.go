package KthLargestElementInAnArray

import (
	"testing"
	"fmt"
)

func TestQuickSortSort(t *testing.T) {
	nums := []int{3,2,1,5,6,4}
	fmt.Println(findKthLargest(nums, 6))
}