package moveZeroes

import (
	"testing"
	"fmt"
)

func TestNumOfIslands(t *testing.T) {
	nums := []int{11,2,3,0,4,0,0,1}
	moveZeroes(nums)
	fmt.Println(nums)
}