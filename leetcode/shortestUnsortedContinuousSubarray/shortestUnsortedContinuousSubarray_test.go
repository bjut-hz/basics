package shortestUnsortedContinuousSubarray

import (
	"testing"
	"fmt"
)

func TestFindUnsortedSubarray(t *testing.T) {
	nums := []int{2, 6, 4, 8, 10, 9, 15}
	fmt.Println(findUnsortedSubarray(nums))
}