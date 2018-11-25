package singleNumber

import (
	"testing"
	"fmt"
)

func TestSingleNumber(t *testing.T) {
	fmt.Println(singleNumber([]int{4,1,2,2,1}))
	fmt.Println(singleNumber1([]int{1,2,2,1, 5}))
}