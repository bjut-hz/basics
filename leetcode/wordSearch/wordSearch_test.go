package wordSearch

import (
	"testing"
	"fmt"
)

func TestExist(t *testing.T) {
	board := [][]byte{
		{'a', 'b'},
	}

	fmt.Println(exist(board, "ba"))
}