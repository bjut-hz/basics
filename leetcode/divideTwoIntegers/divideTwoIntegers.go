package divideTwoIntegers

import "math"

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

func divide(dividend int, divisor int) int {
	if divisor == 0 { return math.MaxInt32 }
	isNegative := false
	if dividend ^ divisor < 0 {
		isNegative = true
	}

	if dividend < 0 {
		dividend = -(dividend)
	}
	if divisor < 0 {
		divisor = -(divisor)
	}


	m := dividend
	n := divisor
	if m < n { return 0 }


	ans := 0
	for m >= n {
		t := n
		p := 1
		for m > (t<<1) {
			t <<= 1
			p <<= 1
		}
		ans += p
		m -= t
	}

	if isNegative {
		ans = -(ans)
	}

	if ans > math.MaxInt32 { return math.MaxInt32 }
	return ans
}