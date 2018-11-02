package removeInvalidParentheses

import (
	"testing"
	"fmt"
)

func TestRemoveInvalidParentheses(t *testing.T) {
	str := ")("
	fmt.Println(removeInvalidParentheses(str))
}