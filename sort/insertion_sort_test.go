package sort

import (
	"testing"
	"fmt"
)

func TestInsertionSort(t *testing.T) {
	nums := []int{2}
	InsertionSort(nums)
	fmt.Println(nums)
}