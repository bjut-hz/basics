package jumpGame

import (
	"testing"
	"fmt"
)

func TestCanJump(t *testing.T) {
	fmt.Println(canJump([]int{0,2,3}))
	fmt.Println(canJump1([]int{0, 2, 3}))
}