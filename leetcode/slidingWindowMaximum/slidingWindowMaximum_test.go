package slidingWindowMaximum

import (
	"testing"
	"fmt"
)

func TestSlidingWindowMaximum(t *testing.T) {
	nums := []int{1,3,-1,-3,5,3,6,7}

	fmt.Println(maxSlidingWindow(nums, 3))
}