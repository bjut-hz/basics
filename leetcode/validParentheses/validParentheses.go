package validParentheses

import "container/list"

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

func isValid(s string) bool {
	if 0 == len(s) { return true }
	stack := list.New()
	// unicode, rune type
	for _, ch := range s {
		if '(' == ch || '[' == ch || '{' == ch {
			stack.PushFront(ch)
			continue
		} else {
			if stack.Len() == 0 {
				return false
			}

			ele := stack.Front()
			top := ele.Value.(int32)
			switch ch {
			case ')': if top != '(' { return false }
			case ']': if top != '[' { return false }
			case '}': if top != '{' { return false }
			default: return false
			}

			// pop
			stack.Remove(ele)
		}
	}

	return 0 == stack.Len()
}
