package bitsOperation

import "math"

func Add(a, b int) int {
	var sum int
	var carry int
	for b != 0 {
		sum = a ^ b
		carry = (a&b) << 1
		a = sum
		b = carry
	}

	return sum
}


// Sub: a - b = a + (-b)
func negative(a int) int {
	return Add(^a, 1)
}

func Sub(a, b int) int {
	return Add(a, negative(b))
}

func Multi(a, b int) int {
	isNegative := false
	if a ^ b < 0 {
		isNegative = true
	}

	if a < 0 {
		a = negative(a)
	}
	if b < 0 {
		b = negative(b)
	}

	ans := 0
	for a != 0 {
		ans = Add(ans, b)
		a = Sub(a, 1)
	}

	if isNegative {
		return negative(ans)
	}
	return ans
}

func Multi1(a, b int) int {
	isNegative := false
	if a ^ b < 0 {
		isNegative = true
	}

	if a < 0 {
		a = negative(a)
	}
	if b < 0 {
		b = negative(b)
	}

	ans := 0
	for b != 0 {
		if b & 1 == 1 {
			ans = Add(ans, a)
		}
		a <<= 1
		b >>= 1
	}

	if isNegative {
		return negative(ans)
	}

	return ans
}

func Divide(a, b int) int {
	if b == 0 { return math.MaxInt32 }

	isNegative := false
	if a ^ b < 0 {
		isNegative = true
	}

	if a < 0 {
		a = negative(a)
	}
	if b < 0 {
		b = negative(b)
	}

	ans := 0
	a = Sub(a, b)
	for a >= 0 {
		ans = Add(ans, 1)
		a = Sub(a, b)
	}

	if isNegative {
		ans = negative(ans)
	}
	return ans
}

func Divide1(dividend, divisor int) int {
	if divisor == 0 { return math.MaxInt32 }
	isNegative := false
	if dividend ^ divisor < 0 {
		isNegative = true
	}

	if dividend < 0 {
		dividend = negative(dividend)
	}
	if divisor < 0 {
		divisor = negative(divisor)
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
		ans = -ans
	}

	if ans > math.MaxInt32 { return math.MaxInt32 }
	return ans
}