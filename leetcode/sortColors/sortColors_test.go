package sortColors


import (
	"testing"
	"fmt"
)

func TestSortColors(t *testing.T) {
	nums := []int{1,2,0}
	sortColors(nums)
	fmt.Println(nums)
}