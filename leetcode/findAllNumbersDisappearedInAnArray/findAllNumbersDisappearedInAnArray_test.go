package findAllNumbersDisappearedInAnArray

import (
	"testing"
	"fmt"
)

func TestFindDisappearedNumbers(t *testing.T) {
	nums := []int{4,3,2,7,8,2,3,1}
	fmt.Println(findDisappearedNumbers(nums))
}