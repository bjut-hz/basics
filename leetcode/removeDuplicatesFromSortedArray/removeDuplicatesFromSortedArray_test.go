package removeDuplicatesFromSortedArray

import (
	"testing"
	"fmt"
)

func TestRemoveDuplicates(t *testing.T) {
	nums := []int{1, 2, 3, 3}
	fmt.Println(removeDuplicates(nums))
	fmt.Println(nums)

	nums = []int{0,0,1,1,1,2,2,3,3,4}
	fmt.Println(removeDuplicates(nums))
	fmt.Println(nums)
}