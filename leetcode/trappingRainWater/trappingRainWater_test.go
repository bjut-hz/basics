package trappingRainWater

import (
	"testing"
	"fmt"
)

func TestTrap(t *testing.T)  {
	fmt.Println(trap([]int{0,1,0,2,1,0,1,3,2,1,2,1}))
	fmt.Println(trap1([]int{0,1,0,2,1,0,1,3,2,1,2,1}))
	fmt.Println(trap2([]int{0,1,0,2,1,0,1,3,2,1,2,1}))
	fmt.Println(trap3([]int{0,1,0,2,1,0,1,3,2,1,2,1}))
}