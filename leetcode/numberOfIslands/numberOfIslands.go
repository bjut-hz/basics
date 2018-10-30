package numberOfIslands


/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and
is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1


Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

func numIslands(grid [][]byte) int {
	m := len(grid)
	if 0 == m {
		return 0
	}
	n := len(grid[0])

	var dfsMark func(i, j int)
	dfsMark = func (i, j int) {
		if i < 0 || i >= m {
			return
		}
		if j < 0 || j >= n {
			return
		}

		if grid[i][j] != '1' {
			return
		}

		grid[i][j] = '0'

		dfsMark(i+1, j)
		dfsMark(i-1, j)
		dfsMark(i, j+1)
		dfsMark(i, j-1)
	}

	count := 0
	for i, a := range grid {
		for j, v := range a {
			if '1' == v {
				count++
				dfsMark(i, j)
			}
		}
	}
	return count
}