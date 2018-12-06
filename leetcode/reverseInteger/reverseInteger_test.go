package reverseInteger

import (
	"testing"
	"fmt"
)

func TestReverse(t *testing.T) {
	//fmt.Println(reverse(-123))
	fmt.Println(1 << 31)
	//fmt.Println(reverse(1 << 31))

	fmt.Println(reverse1(-123))
	fmt.Println(reverse1(1 << 31))
}