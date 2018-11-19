package minimumPathSum

import (
	"math"
)

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

func min2(a, b int) int {
	if a < b { return a }
	return b
}

func minPathSum(grid [][]int) int {
	if 0 == len(grid) { return 0 }
	if 0 == len(grid[0]) { return 0 }

	m := len(grid)
	n := len(grid[0])

	DP := make([][]int, m)
	for i := 0; i < m ; i++ {
		DP[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			DP[i][j] = math.MaxInt32
		}
	}

	// DP init
	DP[0][0] = grid[0][0]
	for i := 1; i < m; i++ {
		DP[i][0] = DP[i-1][0] + grid[i][0]
	}

	for j := 1; j < n; j++ {
		DP[0][j] = DP[0][j-1]+ grid[0][j]
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			DP[i][j] = min2(DP[i-1][j] + grid[i][j], DP[i][j-1] + grid[i][j])
		}
	}

	return DP[m-1][n-1]
}