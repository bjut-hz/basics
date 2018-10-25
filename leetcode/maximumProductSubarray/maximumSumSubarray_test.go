package maximumProductSubarray

import (
	"testing"
	"fmt"
)

func TestMaxSum(t *testing.T) {
	nums := []int{4, -90, 5, -2, -1, 2, 6, -2}
	fmt.Println(maxSum1(nums))

	fmt.Println(maxSum2(nums))

	fmt.Println(maxSum3(nums))

	fmt.Println(maxSum4(nums))
}