package twoSum


import (
	"testing"
	"fmt"
)

func TestTwoSum(t *testing.T) {
	arr := make([]int, 1)
	arr = append(arr, 1, 2, 3, 4, 5, 78)

	fmt.Println(twoSum(arr, 4))
}