package searchA2DMatrixII

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

// we can search from right top
func searchMatrix(matrix [][]int, target int) bool {
	m := len(matrix)
	if 0 == m {
		return false
	}

	n := len(matrix[0])
	if 0 == n {
		return false
	}

	row := 0
	col := n - 1
	for row < m && col >= 0 {
		val := matrix[row][col]
		if target == val {
			return true
		} else if target < val {
			col--
		} else {
			row++
		}
	}
	return false
}