package rotateImage

import (
	"testing"
	"fmt"
)

func TestRotate(t *testing.T) {
	matrix := [][]int{
		{5,1,9,11},
		{2,4,8,10},
		{13,3,6,7},
		{15,14,12,16},
	}
	fmt.Println(matrix)

	rotate(matrix)

	fmt.Println(matrix)
}