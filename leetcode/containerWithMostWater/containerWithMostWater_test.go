package containerWithMostWater

import (
"testing"
"fmt"
)

func TestMaxArea(t *testing.T) {
	height := []int{1,8,6,2,5,4,8,3,7}
	fmt.Println(maxArea(height))
	fmt.Println(maxArea1(height))

}