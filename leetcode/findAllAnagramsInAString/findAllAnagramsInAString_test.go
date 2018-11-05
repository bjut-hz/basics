package findAllAnagramsInAString

import (
	"testing"
	"fmt"
)

func TestFindAnagrams(t *testing.T) {
	fmt.Println(findAnagrams("baa", "aa"))
	fmt.Println(findAnagrams1("baa", "aa"))
	fmt.Println(findAnagrams2("baa", "aa"))
}