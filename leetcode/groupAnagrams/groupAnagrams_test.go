package groupAnagrams

import (
	"testing"
	"fmt"
)

func TestGroupAnagrams(t *testing.T) {
	fmt.Println(groupAnagrams([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
	fmt.Println(groupAnagrams1([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
}