package reversePairs

import (
	"testing"
	"fmt"
)

func TestReversePairs(t *testing.T) {
	arr := [...]int{3, 2, 4, 5, 2, 1, 1}
	fmt.Println(reversePairs(arr[0:]))
}