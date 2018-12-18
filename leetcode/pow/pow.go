package pow

/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
*/

// time space: O(lgN)
func myPow(x float64, n int) float64 {
	if 0 == n { return 1.0 }

	isNegative := false
	if n < 0 {
		n = -n
		isNegative = true
	}
	if n & 0x1 == 1 {
		// odd
		product := x * myPow(x * x, (n-1) / 2)
		if isNegative {
			return 1 / product
		}
		return product
	} else {
		// even
		product := myPow(x * x, n / 2)
		if isNegative {
			return 1 / product
		}
		return product
	}
}