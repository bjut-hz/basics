package romanToInteger

import (
	"testing"
	"fmt"
)

func TestRomanInt(t *testing.T) {
	fmt.Println(romanToInt("III"))
	fmt.Println(romanToInt("IV"))
	fmt.Println(romanToInt("IX"))
	fmt.Println(romanToInt("LVIII"))
	fmt.Println(romanToInt("MCMXCIV"))

	fmt.Println(romanToInt1("III"))
	fmt.Println(romanToInt1("IV"))
	fmt.Println(romanToInt1("IX"))
	fmt.Println(romanToInt1("LVIII"))
	fmt.Println(romanToInt1("MCMXCIV"))
}