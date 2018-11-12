package subarraySumEqualsK


import (
	"testing"
	"fmt"
)

func TestSubarraySum(t *testing.T) {
	nums := []int{1,1,1}
	fmt.Println(subarraySum(nums, 2))
	fmt.Println(subarraySum1(nums, 2))
}