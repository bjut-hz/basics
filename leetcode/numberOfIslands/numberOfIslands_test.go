package numberOfIslands

import (
	"testing"
	"fmt"
)

func TestNumOfIslands(t *testing.T) {
	//grid := [][]byte{{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}}
	//grid := [][]byte{{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}}
	grid := [][]byte{{'1','1','1'}, {'0', '1', '0'}, {'1', '1', '1'}}
	fmt.Println(numIslands(grid))

	fmt.Println(grid)
}