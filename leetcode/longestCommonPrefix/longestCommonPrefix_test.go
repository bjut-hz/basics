package longestCommonPrefix

import (
	"testing"
	"fmt"
)

func TestLongestCommonPrefix(t *testing.T)  {
	strs := []string {
		"aa",
	}
	fmt.Println(longestCommonPrefix(strs))
	fmt.Println(longestCommonPrefix1(strs))
	fmt.Println(longestCommonPrefix2(strs))
	fmt.Println(longestCommonPrefix3(strs))
}