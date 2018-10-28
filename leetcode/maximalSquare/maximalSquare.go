package maximalSquare

import "math"

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

// DP: dp[i][j] represents the side length of the maximum square whose bottom right corner is the cell with index (i,j)
// in the original matrix.
// dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1 (when matrix[i][j] == 1)
func maximalSquare(matrix [][]byte) int {
	m := len(matrix)
	if m == 0 {
		return 0
	}

	n := len(matrix[0])
	dp := make([][]int, m, m)
	for i := range dp {
		dp[i] = make([]int, n, n)
	}

	maxLen := math.MinInt64

	// dp init
	for i, v := range matrix[0] {
		if '1' == v {
			dp[0][i] = 1
			maxLen = 1
		}
	}
	for i, v := range matrix {
		if v[0] == '1' {
			dp[i][0] = 1
			maxLen = 1
		}
	}


	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if '1' == matrix[i][j] {
				dp[i][j] = min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
				if dp[i][j] > maxLen {
					maxLen = dp[i][j]
				}
			}
		}
	}

	return maxLen * maxLen
}

func min3(a, b, c int) int {
	if a <= b && a <= c{
		return a
	}

	if b <= a && b <= c {
		return b
	}

	if c <= a && c <= b {
		return c
	}
	return a
}