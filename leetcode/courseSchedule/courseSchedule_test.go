package courseSchedule

import (
	"testing"
	"fmt"
)

func TestMinStack(t *testing.T) {
	prerequisites := [][]int{{1, 0}, {2, 0}}
	fmt.Println(canFinish(3, prerequisites))
}