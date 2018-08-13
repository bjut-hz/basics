package sort

import (
	"testing"
	"fmt"
)

func TestRadixSort(t *testing.T) {
	arr := []int{64, 8, 216, 512, 27, 729, 0, 1, 343, 125, 332, 333}
	RadixSort(arr, 3, 10)
	for _, v := range arr {
		fmt.Println(v)
	}
}