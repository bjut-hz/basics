package minimumPathSum


import (
	"testing"
	"fmt"
)

func TestMinPathSum(t *testing.T) {
	grid := [][]int{
		{1,3,1},
		{1,5,1},
		{4,2,1},
	}
	fmt.Println(minPathSum(grid))
}