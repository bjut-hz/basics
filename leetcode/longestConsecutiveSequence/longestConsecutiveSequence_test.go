package longestConsecutiveSequence

import (
	"testing"
	"fmt"
)

func TestLongestConsecutive(t *testing.T) {
	fmt.Println(longestConsecutive([]int{0, 1, 2, 2, 3}))
	fmt.Println(longestConsecutive([]int{0, 2, 3}))

	fmt.Println(longestConsecutive1([]int{}))
	fmt.Println(longestConsecutive1([]int{0, 1, 2, 2, 3}))
}