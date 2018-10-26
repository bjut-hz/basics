package houseRobber

import (
	"testing"
	"fmt"
)

func TestRob(t *testing.T) {
	nums := []int{1,2,3,1}
	fmt.Println(rob(nums))
}