package productOfArrayExceptSelf

import (
	"testing"
	"fmt"
)

func TestProductExceptSelf(t *testing.T) {
	nums := []int{1,2}

	fmt.Println(productExceptSelf(nums))
}