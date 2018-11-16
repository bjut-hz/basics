package searchInRotatedSortedArray


import (
	"testing"
	"fmt"
)

func TestSearch(t *testing.T) {
	arr := []int{4,5,6,7,0,1,2}
	fmt.Println(search(arr, 9))
}