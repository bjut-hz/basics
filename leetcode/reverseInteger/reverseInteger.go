package reverseInteger

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

func reverse(x int) int {
	var res int64
	var tmp int64
	tmp = int64(x)
	isNegative := false
	if x < 0 {
		isNegative = true
		tmp = -tmp
	}


	for tmp > 0 {
		remainder := tmp % 10
		tmp /= 10

		res = res * 10 + remainder
	}

	if res > 1 << 31 - 1 || res < -(1 << 31) { return 0 }
	if isNegative {res = -res}
	return int(res)
}

func reverse1(x int) int {
	var res int32
	for x != 0 {
		var t int32
		remainder := int32(x % 10)
		t = int32(res * 10 + remainder)
		if t / 10 != int32(res) { return 0 } // overflow

		res = t
		x /= 10
	}

	return int(res)
}