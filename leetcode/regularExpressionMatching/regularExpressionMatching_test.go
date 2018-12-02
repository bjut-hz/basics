package regularExpressionMatching

import (
	"testing"
	"fmt"
)

func TestIsMatch(t *testing.T) {

	fmt.Println(isMatch1("aasdfasdfasdfasdfas", 	"aasdf.*asdf.*asdf.*asdf.*s"))
	fmt.Println(isMatch1("aa", "a*"))
	fmt.Println(isMatch1("ab", ".*"))
	fmt.Println(isMatch1("aab", "c*a*b"))
	fmt.Println(isMatch1("mississippi", "mis*is*p*."))
	fmt.Println(isMatch1("a", ".*..a"))

}