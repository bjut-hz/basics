package maximalSquare

import (
	"testing"
	"fmt"
)

func TestMajorityElement(t *testing.T) {
	matrix := [][]byte{{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}}
	fmt.Println(maximalSquare(matrix))
	//maximalSquare()
}