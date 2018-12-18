package firstMissingPositive

import (
	"testing"
	"fmt"
)

func TestFirstMissingPositive(t *testing.T) {
	fmt.Println(firstMissingPositive([]int{3,4,-1,1}))
	fmt.Println(firstMissingPositive([]int{0, 2, 1, 1}))

	fmt.Println(firstMissingPositive1([]int{3,4,-1,1}))
	fmt.Println(firstMissingPositive1([]int{0, 2, 1, 1}))

	fmt.Println(firstMissingPositive2([]int{3,4,-1,1}))
	fmt.Println(firstMissingPositive2([]int{0, 2, 1, 1}))
}