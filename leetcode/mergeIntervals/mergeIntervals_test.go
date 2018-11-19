package mergeIntervals


import (
	"testing"
	"fmt"
)

func TestMerge(t *testing.T) {
	intervals := []Interval{
		{Start:1, End:3},
		{Start:2, End:6},
		{Start:8, End:10},
		{Start:15, End:18},
	}
	fmt.Println(merge(intervals))
	//maximalSquare()
}