package longestIncreasingSubsequence


import (
	"testing"
	"fmt"
)

func TestLengthOfLIS(t *testing.T) {
	nums := []int{1,3,6,7,9,4,10,5,6}
	fmt.Println(lengthOfLIS1(nums))
}