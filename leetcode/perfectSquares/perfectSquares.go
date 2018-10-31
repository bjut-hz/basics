package perfectSquares

import (
	"math"
	"container/list"
)

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/


// DP[i] = min(DP[i], DP[i-j*j]+1) 1<= j <= i, DP[0] = 0
func numSquares1(n int) int {
	if n <= 0 {
		return 0
	}

	DP := make([]int, n+1)
	for i := range DP {
		DP[i] = math.MaxInt64
	}
	DP[0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j*j <= i; j++ {
			if DP[i - j*j] < DP[i] {
				DP[i] = DP[i - j*j] + 1
			}
		}
	}
	return DP[n]
}

func numSquares2(n int) int {
	if n <= 0 {
		return 0
	}

	DP := make([]int, 1)
	for len(DP) <= n {
		N := len(DP)
		cnt := math.MaxInt64
		for i := 1; i * i <= N; i++ {
			if cnt > DP[N - i*i] {
				cnt = DP[N - i*i] + 1
			}
		}
		DP = append(DP, cnt)
	}
	return DP[n]
}


// BFS
func numSquares(n int) int {
	cutOff := int(math.Sqrt(float64(n)))
	if cutOff * cutOff == n {
		return 1
	}

	square := make([]int, cutOff + 1)
	queue := list.New()
	ret := make([]int, n + 1)
	for i := 1; i <= cutOff; i++ {
		square[i] = i * i
		queue.PushFront(i * i)
		ret[i * i] = 1
	}

	for 0 != queue.Len() {
		e := queue.Front()
		x := e.Value.(int)
		queue.Remove(e)

		for _, v := range square {
			if v + x <= n && ret[v+x] == 0 {
				ret[v+x] = ret[x] + 1
				queue.PushBack(v + x)
			}
		}
	}

	return ret[n]
}