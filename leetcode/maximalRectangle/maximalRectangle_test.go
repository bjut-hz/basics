package maximalRectangle


import (
	"testing"
	"fmt"
)

func TestMaximalRectangle(t *testing.T) {
	matrix := [][]byte {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'},
	}
	fmt.Println(maximalRectangle(matrix))
}