package stringToInteger

import (
	"testing"
	"fmt"
)

func TestMyAtoi(t *testing.T) {
	fmt.Println(myAtoi(""))
	fmt.Println(myAtoi(" +42"))
	fmt.Println(myAtoi("    -42"))
	fmt.Println(myAtoi("4193 with words"))
	fmt.Println(myAtoi("words and 987"))
	fmt.Println(myAtoi("-91283472332"))
}