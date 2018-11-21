package wordSearch

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

func backTrack(board [][]byte, word string, i, j, cur int, visited *[][]bool) bool {
	if cur == len(word) { return true }

	if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) ||
		cur >= len(word) || board[i][j] != word[cur] || (*visited)[i][j] { return false }

	(*visited)[i][j] = true
	result := backTrack(board, word, i + 1, j, cur + 1, visited) ||
				backTrack(board, word, i - 1, j, cur + 1, visited) ||
				backTrack(board, word, i, j + 1, cur + 1, visited) ||
				backTrack(board, word, i, j - 1, cur + 1, visited)
	(*visited)[i][j] = false

	return result
}

func exist(board [][]byte, word string) bool {
	if 0 == len(board) || 0 == len(board[0]) { return false }

	visited := make([][]bool, len(board))
	for i := 0; i < len(board); i++ {
		visited[i] = make([]bool, len(board[0]))
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if backTrack(board, word, i, j, 0, &visited) {
				return true
			}
		}
	}

	return false
}