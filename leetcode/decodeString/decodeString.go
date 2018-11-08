package decodeString

import (
	"container/list"
)

/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat
numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

func decodeString(s string) string {
	stackNum := list.New()
	stackStr := list.New()
	var isDigit func(byte) bool
	isDigit = func(ch byte) bool {
		if '0' <= ch && ch <= '9' {
			return true
		}
		return false
	}

	N := len(s)
	cnt := 0
	str := ""
	for i := 0; i < N; i++ {
		if isDigit(s[i]) {
			cnt = cnt * 10 + int(s[i] - '0')
		} else if '[' == s[i] {
			stackNum.PushFront(cnt)
			stackStr.PushFront(str)
			cnt = 0
			str = ""
		} else if ']' == s[i] {
			eleStr := stackStr.Front()
			eleNum := stackNum.Front()
			stackNum.Remove(eleNum)
			times := eleNum.Value.(int)

			tmp := eleStr.Value.(string)
			for i := 0; i < times; i++ {
				tmp += str
			}
			str = tmp
			stackStr.Remove(eleStr)
		} else {
			// alphabet
			str += string(s[i])
		}
	}
	return str
}

func decodeString1(s string) string {
	var isDigit func(byte) bool
	isDigit = func(ch byte) bool {
		if '0' <= ch && ch <= '9' {
			return true
		}
		return false
	}

	N := len(s)
	var dfs func(*int) string
	dfs = func(k *int) string {
		cnt := 0
		str := ""
		for *k < N {
			if isDigit(s[*k]) {
				cnt = cnt * 10 + int(s[*k] - '0')
				*k++
			} else if '[' == s[*k] {
				*k++
				result := dfs(k)
				for i := 0; i < cnt; i++ {
					str += result
				}
				cnt = 0
			} else if ']' == s[*k] {
				*k++
				return str
			} else {
				str += string(s[*k])
				*k++
			}
		}
		return str
	}

	i := 0
	return dfs(&i)
}