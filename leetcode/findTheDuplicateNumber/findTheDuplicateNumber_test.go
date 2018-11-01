package findTheDuplicateNumber

import (
	"testing"
	"fmt"
)

func TestFindDuplicate(t *testing.T) {
	nums := []int{1,3,4,2,2}

	fmt.Println(findDuplicate(nums))

	fmt.Println(findDuplicate1(nums))
}