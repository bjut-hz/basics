package implementstrStr

import (
	"testing"
	"fmt"
)

func TestStrStr(t *testing.T) {
	fmt.Println(strStr("a", "a"))
	fmt.Println(strStr("aaaaa", "baa"))
}