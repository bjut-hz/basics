package subsets


import (
	"testing"
	"fmt"
)

func TestSubsets(t *testing.T) {
	fmt.Println(subsets([]int{1, 2, 3}))
	fmt.Println(subsets1([]int{1, 2, 3}))
	fmt.Println(subsets2([]int{1, 2, 3}))
}