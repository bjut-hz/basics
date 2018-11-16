package findFirstAndLastPositionOfElementInSortedArray


import (
	"testing"
	"fmt"
)

func TestSearchRange(t *testing.T) {
	nums := []int{5,7,7,8,8,10}

	fmt.Println(searchRange(nums, 7))
}