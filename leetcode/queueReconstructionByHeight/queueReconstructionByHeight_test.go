package queueReconstructionByHeight


import (
	"testing"
	"fmt"
)

func TestReconstructQueue(t *testing.T) {
	people := [][]int{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}}

	fmt.Println(reconstructQueue(people))
}