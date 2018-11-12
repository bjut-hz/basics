package taskScheduler


import (
	"testing"
	"fmt"
)

func TestLeastInterval(t *testing.T) {
	nums := []byte{'A','A','A','B','B','B'}
	fmt.Println(leastInterval(nums, 2))
}