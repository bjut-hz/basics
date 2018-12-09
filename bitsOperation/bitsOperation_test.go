package bitsOperation

import (
	"testing"
	"fmt"
	"math"
)

func TestAll(t *testing.T) {
	fmt.Println(Add(1, 999))
	fmt.Println(Sub(1, 999))
	fmt.Println(Multi(2, -9))
	fmt.Println(Multi1(2, -9))
	fmt.Println(Divide(-91, 0))
	fmt.Println(Divide1(math.MinInt32, -1))
	fmt.Println(Divide1(9, 0))

}