package countAndSay

import (
	"testing"
	"fmt"
)

func TestCountAndSay(t *testing.T) {
	for i := 1; i < 10; i++ {
		fmt.Println(countAndSay(i))
	}
	//fmt.Println(countAndSay(3))
	//fmt.Println(countAndSay(4))

}