package medianOfTwoSortedArrays


import (
	"testing"
	"fmt"
)

func TestFindMedianSortedArrays(t *testing.T) {
	fmt.Println(findMedianSortedArrays([]int{1,3}, []int{2}))
	fmt.Println(findMedianSortedArrays([]int{1,2}, []int{3, 4}))
}